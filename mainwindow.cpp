#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    objlist = new QStringListModel(this);
    ui->objslist->setModel(objlist);

    polypointslist = new QStringListModel(this);
    ui->polypointlist->setModel(polypointslist);
    polypointslist->setStringList(polystring);

    ui->objslist->setSelectionMode(QAbstractItemView::ExtendedSelection);

    displayFile.push_back(new DisplayFileObject(new Point(new Coordinate(10, 10))
                                                ,"ponto"));
    displayFile.push_back(new DisplayFileObject(new Line(new Coordinate(20, 20), new Coordinate(100,100))
                                                ,"linha"));
    Polygon *p = new Polygon();
    p->addPoint(new Coordinate(50, 50));
    p->addPoint(new Coordinate(100, 50));
    p->addPoint(new Coordinate(100, 100));
    p->addPoint(new Coordinate(50, 100));
    displayFile.push_back(new DisplayFileObject(p, "Poly"));

    viewPortTransformation();

    ui->canvas->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonplus_clicked()
{
    wMaxX = wMaxX * 1.1;
    wMaxY = wMaxY * 1.1;
    viewPortTransformation();
    ui->canvas->update();
    //redraw();
}

void MainWindow::on_buttonminus_clicked()
{
    wMaxX = wMaxX * 0.9;
    wMaxY = wMaxY * 0.9;
    viewPortTransformation();
    ui->canvas->update();
    //redraw();
}

void MainWindow::on_buttonup_clicked()
{
    wMaxY += 10.0;
    wMinY += 10.0;
    viewPortTransformation();
    ui->canvas->update();
    //redraw();
}

void MainWindow::on_buttondown_clicked()
{
    wMaxY -= 10.0;
    wMinY -= 10.0;
    viewPortTransformation();
    ui->canvas->update();

    //redraw();
}

void MainWindow::on_buttonleft_clicked()
{
    wMaxX += 10.0;
    wMinX += 10.0;
    ui->canvas->update();
    viewPortTransformation();
    //redraw();
}

void MainWindow::on_buttonright_clicked()
{
    wMaxX -= 10.0;
    wMinX -= 10.0;
    viewPortTransformation();
    ui->canvas->update();
    //redraw();
}

void MainWindow::on_createpoint_clicked()
{
    std::string name = ui->namepoint->toPlainText().toStdString();
    float x = ui->xpoint->toPlainText().toFloat();
    float y = ui->ypoint->toPlainText().toFloat();
    Coordinate * coor = new Coordinate(x, y);
    Point * p = new Point(coor);
    DisplayFileObject * d = new DisplayFileObject(p, name);
    displayFile.push_back(d);
    viewPortTransformation();
    ui->canvas->update();
    ui->namepoint->clear();
    ui->xpoint->clear();
    ui->ypoint->clear();
    //redraw();
}

void MainWindow::on_createline_clicked()
{
    std::string name = ui->nameline->toPlainText().toStdString();
    float xi = ui->xiline->toPlainText().toFloat();
    float yi = ui->yiline->toPlainText().toFloat();
    float xf = ui->xfline->toPlainText().toFloat();
    float yf = ui->yfline->toPlainText().toFloat();
    Coordinate * coor1 = new Coordinate(xi, yi);
    Coordinate * coor2 = new Coordinate(xf, yf);
    Line * l = new Line(coor1, coor2);
    DisplayFileObject * d = new DisplayFileObject(l, name);
    displayFile.push_back(d);
    viewPortTransformation();
    ui->canvas->update();
    ui->nameline->clear();
    ui->xiline->clear();
    ui->yiline->clear();
    ui->xfline->clear();
    ui->yfline->clear();
    //redraw();
}

void MainWindow::on_addpolypoint_clicked()
{
    float x = ui->polyxpoint->toPlainText().toFloat();
    float y = ui->polyypoint->toPlainText().toFloat();
    Coordinate * coor = new Coordinate(x, y);
    polyPoints.push_back(coor);
    polystring << ui->polyxpoint->toPlainText() + "," + ui->polyypoint->toPlainText();
    polypointslist->setStringList(polystring);
    ui->polyxpoint->clear();
    ui->polyypoint->clear();
    //redraw();
}
void MainWindow::on_buttonmove_clicked(){
    int r = ui->objslist->currentIndex().row();
    if (r == -1){
        r = 0;
    }
    float vx = ui->xmove->toPlainText().toFloat();
    float vy = ui->ymove->toPlainText().toFloat();
    Coordinate * coor = new Coordinate(vx, vy);
    DisplayFileObject * d = displayFile.at(r);
    d->move(coor);
    viewPortTransformation();
    ui->canvas->update();
}

void MainWindow::on_buttonscale_clicked(){
    int r = ui->objslist->currentIndex().row();
    if (r == -1){
        r = 0;
    }
    float fx = ui->fxscale->toPlainText().toFloat();
    float fy = ui->fyscale->toPlainText().toFloat();
    Coordinate * coor = new Coordinate(fx, fy);
    DisplayFileObject * d = displayFile.at(r);
    d->scale(coor);
    viewPortTransformation();
    ui->canvas->update();
}

void MainWindow::on_buttonrotate_clicked(){
    int r = ui->objslist->currentIndex().row();
    if (r == -1){
        r = 0;
    }
    float factor = ui->rotatefactor->toPlainText().toFloat();
    DisplayFileObject * d = displayFile.at(r);
    d->rotate(factor);
    viewPortTransformation();
    ui->canvas->update();
}

void MainWindow::on_createpoly_clicked()
{
    std::string name = ui->namepolygon->toPlainText().toStdString();
    float x = ui->polyxpoint->toPlainText().toFloat();
    float y = ui->polyypoint->toPlainText().toFloat();
    Coordinate * coor = new Coordinate(x, y);
    polyPoints.push_back(coor);
    Polygon * p = new Polygon();
    for(int i =0; i < polyPoints.size(); i++){
        p->addPoint(polyPoints.at(i));
    }
    DisplayFileObject * d = new DisplayFileObject(p, name);
    displayFile.push_back(d);
    viewPortTransformation();
    ui->canvas->update();
    ui->namepolygon->clear();
    ui->polyxpoint->clear();
    ui->polyypoint->clear();
    polystring.clear();
    polypointslist->setStringList(polystring);
    //redraw();
}

Coordinate* MainWindow::getViewPortCoordinates(Coordinate* worldCoord) {
    float vpx = ((worldCoord->x()-wMinX)/(wMaxX-wMinX))*(vpMaxX);
    float vpy = (1-((worldCoord->y()-wMinY)/(wMaxY-wMinY)))*(vpMaxY);
    return new Coordinate(vpx, vpy);
}

void MainWindow::viewPortTransformation()
{
    std::vector<DisplayFileObject*> transformed;
    QStringList list;
    for(int i = 0; i < displayFile.size(); i++){
        DisplayFileObject * obj = displayFile.at(i);
        std::string type = obj->getType();
        list << QString::fromStdString(obj->getName());
        if(type == "point"){
            Coordinate * coor = getViewPortCoordinates(obj->getCoordinates().at(0));
            Point * p = new Point(coor);
            DisplayFileObject * dispobj = new DisplayFileObject(p, obj->getName());
            transformed.push_back(dispobj);
        }
        else if(type == "line"){
            std::vector<Coordinate*> c = obj->getCoordinates();
            Coordinate * coor1 = getViewPortCoordinates(c.at(0));
            Coordinate * coor2 = getViewPortCoordinates(c.at(1));
            Line * l = new Line(coor1, coor2);
            DisplayFileObject * dispobj = new DisplayFileObject(l, obj->getName());
            transformed.push_back(dispobj);
        }
        else{
            Polygon * p = new Polygon();
            std::vector<Coordinate*> c = obj->getCoordinates();
            for(int j = 0; j < c.size(); j++){
                Coordinate * coor = getViewPortCoordinates(c.at(j));
                p->addPoint(coor);
            }
            DisplayFileObject * dispobj = new DisplayFileObject(p, obj->getName());
            transformed.push_back(dispobj);
        }
    }
    objlist->setStringList(list);
    ui->canvas->updateObjects(transformed);
}
