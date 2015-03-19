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
    wMaxY = wMaxY + 1.0;
    viewPortTransformation();
    ui->canvas->update();
    //redraw();
}

void MainWindow::on_buttondown_clicked()
{
    wMaxY = wMaxY - 1.0;
    viewPortTransformation();
    ui->canvas->update();
    //redraw();
}

void MainWindow::on_buttonleft_clicked()
{
    wMaxX = wMaxX + 1.0;
    ui->canvas->update();
    viewPortTransformation();
    //redraw();
}

void MainWindow::on_buttonright_clicked()
{
    wMaxX = wMaxX - 1.0;
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
    Coordinate * coor = new Coordinate(50.0, 50.0);
    DisplayFileObject * d = displayFile.at(0);
    d->move(coor);
    //viewPortTransformation();
    //ui->canvas->update();
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

void MainWindow::viewPortTransformation()
{
    std::vector<DisplayFileObject*> transformed;
    QStringList list;
    for(int i = 0; i < displayFile.size(); i++){
        DisplayFileObject * obj = displayFile.at(i);
        std::string type = obj->getType();
        list << QString::fromStdString(obj->getName());
        if(type == "point"){
            Coordinate * c = obj->getCoordinates().at(0);
            float vpx = (c->x()/wMaxX)*(vpMaxX);
            float vpy = (1-(c->y()/wMaxY))*(vpMaxY);
            Coordinate * coor = new Coordinate(vpx, vpy);
            Point * p = new Point(coor);
            DisplayFileObject * dispobj = new DisplayFileObject(p, obj->getName());
            transformed.push_back(dispobj);
        }
        else if(type == "line"){
            std::vector<Coordinate*> c = obj->getCoordinates();
            float vpx1 = (c.at(0)->x()/wMaxX)*(vpMaxX);
            float vpy1 = (1-(c.at(0)->y()/wMaxY))*(vpMaxY);
            float vpx2 = (c.at(1)->x()/wMaxX)*(vpMaxX);
            float vpy2 = (1-(c.at(1)->y()/wMaxY))*(vpMaxY);
            Coordinate * coor1 = new Coordinate(vpx1, vpy1);
            Coordinate * coor2 = new Coordinate(vpx2, vpy2);
            Line * l = new Line(coor1, coor2);
            DisplayFileObject * dispobj = new DisplayFileObject(l, obj->getName());
            transformed.push_back(dispobj);
        }
        else{
            Polygon * p = new Polygon();
            std::vector<Coordinate*> c = obj->getCoordinates();
            for(int j = 0; j < c.size(); j++){
                float vpx = (c.at(j)->x()/wMaxX)*(vpMaxX);
                float vpy = (1-(c.at(j)->y()/wMaxY))*(vpMaxY);
                Coordinate * coor = new Coordinate(vpx, vpy);
                p->addPoint(coor);
            }
            DisplayFileObject * dispobj = new DisplayFileObject(p, obj->getName());
            transformed.push_back(dispobj);
        }
    }
    objlist->setStringList(list);
    ui->canvas->updateObjects(transformed);
}
