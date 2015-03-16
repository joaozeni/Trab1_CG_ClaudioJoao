#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QListWidgetItem>
#include <QtGui>
#include <QWidget>
#include <QPainter>
#include "objects/diplayFileObject"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *e);

private:
    Ui::MainWindow *ui;
    DisplayFile * displayFile;

    const float vpMinX = 0.0;
    const float vpMinY = 0.0;
    const float vpMaxX = 500.0;
    const float vpMaxY = 500.0;

    float wMinX = 0.0;
    float wMinY = 0.0;
    float wMaxX = 500.0;
    float wMaxY = 500.0;

    void redraw();
    void viewPortTransformation();

private slots:
    void on_botaobaixo_clicked();
    void on_botaocima_clicked();
    void on_botaoladod_clicked();
    void on_botaoladoe_clicked();
    void on_botaomais_clicked();
    void on_botaomenos_clicked();
    //void on_addobj_clicked();
    void on_createpoint_clicked();
    void on_createline_clicked();
};

#endif
