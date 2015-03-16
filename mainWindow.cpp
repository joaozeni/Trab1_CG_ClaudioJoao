#include "mainWindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayfile = new DisplayFile();

    redraw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * evento){
    switch(evento->key()){
    case Qt::Key_Up:
    on_botaocima_clicked();
	break;
    case Qt::Key_Down:
    on_botaobaixo_clicked();
	break;
    case Qt::Key_Left:
    on_botaoladoe_clicked();
	break;
    case Qt::Key_Right:
    on_botaoladod_clicked();
	break;
    case Qt::Key_Plus:
    on_botaomais_clicked();
	break;
    case Qt::Key_Minus:
    on_botaomenos_clicked();
	break;
    case Qt::Key_Escape:
	exit(0);
    }
}

void MainWindow::redraw(){
    ui->canvas->update();
}

void MainWindow::on_botaobaixo_clicked()
{
}

void MainWindow::on_botaocima_clicked()
{
}

void MainWindow::on_botaoladod_clicked()
{
}

void MainWindow::on_botaoladoe_clicked()
{
}

void MainWindow::on_botaomais_clicked()
{
    wMaxX = wMaxX * 1.1;
    wMaxY = wMaxY * 1.1;
    viewPortTransformation();
    redraw();
}

void MainWindow::on_botaomenos_clicked()
{
	wMaxX = wMaxX * 0.9;
    wMaxY = wMaxY * 0.9;
    viewPortTransformation();
    redraw();
}

void MainWindow::on_createpoint_clicked()
{
    std::string name = ui->namepoint->toPlainText().toStdString();
    float x = ui->pointx->toPlainText().toFloat();
    float y = ui->pointy->toPlainText().toFloat();
    Coordinate * coor = new Coordinate(x, y);
    Point p;
    p.c = coor;
    DisplayFileObject * d = new DisplayFileObject(p, name, "point");
    displayfile->addObject(d);
    viewPortTransformation();
    redraw();
}


void MainWindow::on_createline_clicked()
{
    std::string name = ui->nameline->toPlainText().toStdString();
    float xi = ui->pointix->toPlainText().toFloat();
    float yi = ui->pointiy->toPlainText().toFloat();
    float xf = ui->pointfx->toPlainText().toFloat();
    float yf = ui->pointfy->toPlainText().toFloat();
    Coordinate * coor1 = new Coordinate(xi, yi);
    Coordinate * coor2 = new Coordinate(xf, yf);
    Line l;
    Coordinate* coors[2] = {coor1, coor2};
    l.c = coors;
    DisplayFileObject * d = new DisplayFileObject(l, name, "line");
    displayfile->addObject(d);
    viewPortTransformation();
    redraw();
}

void MainWindow::viewPortTransformation()
{
    DisplayFileObject * dispobj;
	DisplayFile * transformed = new DisplayFile();
    std::vector<DisplayFileObject> objs = displayFile->getObjects();
    std::vector<DisplayFileObject>::iterator obj = objs.begin();
    while(obj != obj.end()){
        string type = obj.getType();
        if(type == "point"){
            Coordinate c = obj.getCoordinates();
            float vpx = (c.x()/wMaxX)*(vpMaxX);
            float vpy = (1-(c.y()/wMaxY))*(vpMaxY);
            Point p;
            Coordinate coor = new Coordinate(vpx, vpy);
            p.c = coor;
            dispobj = new DisplayFileObject(p, obj.getName(), "point");
            transformed->addObject(dispobj);
        }
        else if(type == "line"){
            Coordinate c[2] = obj.getCoordinates();
            float vpx1 = (c[0].x()/wMaxX)*(vpMaxX);
            float vpy1 = (1-(c[0].y()/wMaxY))*(vpMaxY);
            float vpx2 = (c[1].x()/wMaxX)*(vpMaxX);
            float vpy2 = (1-(c[1].y()/wMaxY))*(vpMaxY);
            Coordinate coor1 = new Coordinate(vpx1, vpyi1;
            Coordinate coor2 = new Coordinate(vpx2, vpy2);
            Coordinate coors[2] = {coor1, coor2};
            Line l;
            l.c = coors;
            dispobj = new DisplayFileObject(l, obj.getName(), "line");
            transformed->addObject(dispobj);
        }
        else{
            break;
        }
    }
    ui->canvas->updateObjects(transformed);
}
