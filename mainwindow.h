#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QStringList>
#include <QStringListModel>
#include "displayfileobject.h"
#include "coordinate.h"
#include "qviewport.h"
#include "window.h"

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
    float wMaxX = 550.0;
    float wMaxY = 550.0;

    bool drawingLine = false;

    QStringListModel *objlist;
    QStringListModel *polypointslist;
    QStringListModel *curvepointslist;
    QStringList polystring;
    QStringList curvestring;

    void viewPortTransformation();
    Coordinate* getViewPortCoordinates(Coordinate* worldCoord);

    //std::vector<DisplayFileObject*> displayFile;

    Window * window;

    std::vector<Coordinate*> polyPoints;
    std::vector<Coordinate*> curvePoints;

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
    void on_createcurve_clicked();
    void on_addpolypoint_clicked();
    void on_addcurvepoint_clicked();
    void on_buttonmove_clicked();
    void on_buttonscale_clicked();
    void on_buttonrotate_clicked();
    void on_buttonrotatewindow_clicked();

    void clickdrag_createline(bool release, int x, int y);

    void loadObj(QString filename);
    bool eventFilter(QObject *object, QEvent *event);

    void updateScreen();
    void on_open_obj_btn_clicked();
};

#endif // MAINWINDOW_H
