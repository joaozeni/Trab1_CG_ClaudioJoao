#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QStringList>
#include <QStringListModel>
#include "displayfileobject.h"
#include "coordinate.h"
#include "qviewport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    const float vpMinX = 0.0;
    const float vpMinY = 0.0;
    const float vpMaxX = 550.0;
    const float vpMaxY = 550.0;

    float wMinX = 0.0;
    float wMinY = 0.0;
    float wMaxX = 500.0;
    float wMaxY = 500.0;

    QStringListModel *objlist;
    QStringListModel *polypointslist;
    QStringList polystring;

    void viewPortTransformation();
    Coordinate* getViewPortCoordinates(Coordinate* worldCoord);

    std::vector<DisplayFileObject*> displayFile;
    std::vector<Coordinate*> polyPoints;

    //DisplayFileObject * obj = new DisplayFileObject();

private slots:
    void on_buttondown_clicked();
    void on_buttonup_clicked();
    void on_buttonright_clicked();
    void on_buttonleft_clicked();
    void on_buttonplus_clicked();
    void on_buttonminus_clicked();
    //void on_addobj_clicked();
    void on_createpoint_clicked();
    void on_createline_clicked();
    void on_createpoly_clicked();
    void on_addpolypoint_clicked();
    void on_buttonmove_clicked();
    void on_buttonscale_clicked();
    void on_buttonrotate_clicked();
};

#endif // MAINWINDOW_H
