#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <QFileDialog>

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

    viewPortTransformation();

    //updateScreen();

    QApplication::instance()->installEventFilter(this);

    ui->label_status->setText("Bem vindo");
    ui->frame->setStyleSheet("border: 1px solid red");


    ui->canvas->update();
}

void MainWindow::loadObj(QString filename) {
    std::vector<Coordinate> coords;
    std::string line;
    std::ifstream myfile (filename.toStdString().c_str());
    std::string current_object = "";
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            std::stringstream iss(line);
            std::string command;
            getline(iss, command, ' ');
            if(command == "v") {
                float x;
                float y;
                float z;
                std::string element;
                getline(iss, element, ' ');
                x = std::atof(element.c_str());
                getline(iss, element, ' ');
                y = std::atof(element.c_str());
                getline(iss, element, ' ');
                z = std::atof(element.c_str());
                coords.push_back(Coordinate(x,y,z));
            } else if(command == "o") {
                getline(iss, current_object, ' ');
            } else if(command == "p") {
                std::string coord;
                getline(iss, coord, ' ');
                int n = std::atoi(coord.c_str())-1;
                displayFile.push_back(new DisplayFileObject(
                                          new Point(coords.at(n)),
                                          current_object
                                          )
                                      );
            } else if(command == "f") {
                Polygon* p = new Polygon();
                std::string coord;
                while(getline(iss, coord, ' ')) {
                    int n = std::atoi(coord.c_str())-1;
                    Coordinate c = coords.at(n);
                    p->addPoint(c);
                }
                displayFile.push_back(new DisplayFileObject(p, current_object));
            }  else if(command == "l") {
                int spaces = std::count(line.begin(), line.end(), ' ');
                if(spaces == 2) {// LINHA
                    std::string coord;
                    getline(iss, coord, ' ');
                    int a = std::atoi(coord.c_str())-1;
                    getline(iss, coord, ' ');
                    int b = std::atoi(coord.c_str())-1;
                    displayFile.push_back(new DisplayFileObject(
                                              new Line(coords.at(a), coords.at(b)),
                                              current_object
                                              )
                                          );
                } else { // POLIGONO
                    Polygon* p = new Polygon();
                    std::string coord;
                    while(getline(iss, coord, ' ')) {
                        int n = std::atoi(coord.c_str())-1;
                        Coordinate c = coords.at(n);
                        p->addPoint(c);
                    }
                    displayFile.push_back(new DisplayFileObject(p, current_object));
                }
            }

        }
        myfile.close();
    }
    viewPortTransformation();
}

bool MainWindow::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::KeyPress) {
    QKeyEvent* e = static_cast<QKeyEvent*>(event);
    bool ret = true;
    switch(e->key()) {
        case Qt::Key_Up: this->on_buttonup_clicked(); break;
        case Qt::Key_Down: this->on_buttondown_clicked(); break;
        case Qt::Key_Left: this->on_buttonleft_clicked(); break;
        case Qt::Key_Right: this->on_buttonright_clicked(); break;
        case Qt::Key_Plus: this->on_buttonplus_clicked(); break;
        case Qt::Key_Minus: this->on_buttonminus_clicked(); break;
    default: ret = false;
    }
    return ret;
  } else if (event->type() == QEvent::MouseButtonPress) {
    QMouseEvent* e = static_cast<QMouseEvent*>(event);
    clickdrag_createline(false, e->x(), e->y());
  }
  return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateScreen()
{
    ui->label_botlef->setText(QString::number(wMinX) + ", " + QString::number(wMinY));
    ui->label_botrig->setText(QString::number(wMaxX));
    ui->label_toplef->setText(QString::number(wMaxY));
}

void MainWindow::on_buttonplus_clicked()
{
    int viewportXSize = wMaxX - wMinX;
    int viewportYSize = wMaxY - wMinY;
    float factor = 0.1;
    wMaxX -= viewportXSize*factor;
    wMaxY -= viewportYSize*factor;
    wMinX += viewportXSize*factor;
    wMinY += viewportYSize*factor;

    viewPortTransformation();
    ui->canvas->update();
    //redraw();
}

void MainWindow::on_buttonminus_clicked()
{
    int viewportXSize = wMaxX - wMinX;
    int viewportYSize = wMaxY - wMinY;
    float factor = 0.1;
    wMaxX += viewportXSize*factor;
    wMaxY += viewportYSize*factor;
    wMinX -= viewportXSize*factor;
    wMinY -= viewportYSize*factor;
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
    wMaxX -= 10.0;
    wMinX -= 10.0;
    ui->canvas->update();
    viewPortTransformation();
    //redraw();
}

void MainWindow::on_buttonright_clicked()
{
    wMaxX += 10.0;
    wMinX += 10.0;
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

void MainWindow::clickdrag_createline(bool release, int x, int y)
{
    //x -= ui->frame->x()+10;
    //y = vpMaxY-(y-ui->frame->y())+10;
    ui->label_status->setText(QString::number(x) + ", " + QString::number(y));
}

void MainWindow::on_createline_clicked()
{
    std::string name = ui->nameline->toPlainText().toStdString();
    float xi = ui->xiline->toPlainText().toFloat();
    float yi = ui->yiline->toPlainText().toFloat();
    float xf = ui->xfline->toPlainText().toFloat();
    float yf = ui->yfline->toPlainText().toFloat();

    if(name == "")
        return;
    if(xi == 0.0 && yi == 0.0 && xf == 0.0 && yf == 0.0) {
        drawingLine = true;
        ui->label_status->setText("Clique na tela");
    } else {
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
    }
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
    updateScreen();
    ui->canvas->updateObjects(transformed);
}

void MainWindow::on_open_obj_btn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open File"), "/home", tr("OBJ Files (*.obj)"));
    loadObj(fileName);
}
