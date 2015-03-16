#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	viewPort = new ViewPort(100, 100, 200, 100);
    //p = new QPainter(ui->canvasframe->canvas);
    ui->setupUi(this);

    redraw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * evento){
    switch(evento->key()){
    case Qt::Key_Up:
	on_windowCima_clicked();
	break;
    case Qt::Key_Down:
	on_windowBaixo_clicked();
	break;
    case Qt::Key_Left:
	on_windowEsquerda_clicked();
	break;
    case Qt::Key_Right:
	on_windowDireito_clicked();
	break;
    case Qt::Key_Plus:
	on_zoomInButton_clicked();
	break;
    case Qt::Key_Minus:
	on_zoomOutButton_clicked();
	break;
    case Qt::Key_Escape:
	exit(0);
    }
}

void gui::redraw(){
    ui->canvas-update();
}

// void MainWindow::on_botaobaixo_clicked()
// {
// }

// void MainWindow::on_botaocima_clicked()
// {
// }

// void MainWindow::on_botaoladod_clicked()
// {
// }

// void MainWindow::on_botaoladoe_clicked()
// {
// }

// void MainWindow::on_botaomais_clicked()
// {
// }

// void MainWindow::on_botaomenos_clicked()
// {
// }

void MainWindow::on_createpoint_clicked()
{
    std::string name = ui->namepoint->text().latin1();
    float x = atof(ui->pointx->text());
    float y = atof(ui->pointy->text());
    Coordinate coor = new Coordinate(x, y);
    Point p;
    p.c = coor;
    DisplayFileObject d = new DisplayFileObject(p, name);
    diplayFile->addObject(d);
    redraw();
}


void MainWindow::on_createline_clicked()
{
    std::string name = ui->nameline->text().latin1();
    float xi = atof(ui->pointix->text());
    float yi = atof(ui->pointiy->text());
    float xf = atof(ui->pointfx->text());
    float yf = atof(ui->pointfy->text());
    Coordinate coor1 = new Coordinate(xi, yi);
    Coordinate coor2 = new Coordinate(xf, yf);
    Line l;
    Coordinate coors[2] = {coor1, coor2};
    l.c = coors;
    DisplayFileObject d = new DisplayFileObject(l, name);
    diplayFile->addObject(d);
    redraw();
}
