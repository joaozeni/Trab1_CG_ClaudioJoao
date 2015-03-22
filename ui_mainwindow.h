/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qviewport.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListView *objslist;
    QGridLayout *gridLayout;
    QLabel *label_20;
    QLabel *label_19;
    QPushButton *buttonmove;
    QPlainTextEdit *ymove;
    QPlainTextEdit *fyscale;
    QPushButton *buttonscale;
    QLabel *label_13;
    QPlainTextEdit *xmove;
    QLabel *label_18;
    QLabel *label_17;
    QPlainTextEdit *fxscale;
    QPlainTextEdit *rotatefactor;
    QPushButton *buttonrotate;
    QFrame *frame;
    Qviewport *canvas;
    QTabWidget *tabWidget;
    QWidget *Ponto;
    QLabel *label;
    QPlainTextEdit *namepoint;
    QPlainTextEdit *xpoint;
    QLabel *label_2;
    QPlainTextEdit *ypoint;
    QLabel *label_3;
    QPushButton *createpoint;
    QWidget *Reta;
    QLabel *label_7;
    QPlainTextEdit *nameline;
    QPlainTextEdit *yiline;
    QLabel *label_8;
    QPlainTextEdit *xiline;
    QLabel *label_9;
    QPlainTextEdit *yfline;
    QLabel *label_10;
    QPlainTextEdit *xfline;
    QLabel *label_11;
    QPushButton *createline;
    QWidget *polygon;
    QListView *polypointlist;
    QPlainTextEdit *polyxpoint;
    QLabel *label_4;
    QPlainTextEdit *polyypoint;
    QPushButton *addpolypoint;
    QPlainTextEdit *namepolygon;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *createpoly;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QPushButton *buttonplus;
    QPushButton *buttonminus;
    QPushButton *buttonup;
    QPushButton *buttondown;
    QPushButton *buttonleft;
    QPushButton *buttonright;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1177, 627);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 291, 346));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        objslist = new QListView(verticalLayoutWidget);
        objslist->setObjectName(QString::fromUtf8("objslist"));
        objslist->setEnabled(true);
        objslist->setMinimumSize(QSize(289, 90));
        objslist->setMaximumSize(QSize(289, 90));

        verticalLayout->addWidget(objslist);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_20 = new QLabel(verticalLayoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout->addWidget(label_20, 0, 1, 1, 1);

        label_19 = new QLabel(verticalLayoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 0, 0, 1, 1);

        buttonmove = new QPushButton(verticalLayoutWidget);
        buttonmove->setObjectName(QString::fromUtf8("buttonmove"));

        gridLayout->addWidget(buttonmove, 1, 2, 1, 1);

        ymove = new QPlainTextEdit(verticalLayoutWidget);
        ymove->setObjectName(QString::fromUtf8("ymove"));
        ymove->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(ymove, 1, 1, 1, 1);

        fyscale = new QPlainTextEdit(verticalLayoutWidget);
        fyscale->setObjectName(QString::fromUtf8("fyscale"));
        fyscale->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(fyscale, 3, 1, 1, 1);

        buttonscale = new QPushButton(verticalLayoutWidget);
        buttonscale->setObjectName(QString::fromUtf8("buttonscale"));

        gridLayout->addWidget(buttonscale, 3, 2, 1, 1);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        xmove = new QPlainTextEdit(verticalLayoutWidget);
        xmove->setObjectName(QString::fromUtf8("xmove"));
        xmove->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(xmove, 1, 0, 1, 1);

        label_18 = new QLabel(verticalLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 2, 0, 1, 1);

        fxscale = new QPlainTextEdit(verticalLayoutWidget);
        fxscale->setObjectName(QString::fromUtf8("fxscale"));
        fxscale->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(fxscale, 3, 0, 1, 1);

        rotatefactor = new QPlainTextEdit(verticalLayoutWidget);
        rotatefactor->setObjectName(QString::fromUtf8("rotatefactor"));
        rotatefactor->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(rotatefactor, 5, 0, 1, 1);

        buttonrotate = new QPushButton(verticalLayoutWidget);
        buttonrotate->setObjectName(QString::fromUtf8("buttonrotate"));

        gridLayout->addWidget(buttonrotate, 5, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(310, 0, 550, 550));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        canvas = new Qviewport(frame);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        canvas->setGeometry(QRect(0, 0, 550, 550));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(870, 0, 291, 541));
        Ponto = new QWidget();
        Ponto->setObjectName(QString::fromUtf8("Ponto"));
        label = new QLabel(Ponto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 59, 16));
        namepoint = new QPlainTextEdit(Ponto);
        namepoint->setObjectName(QString::fromUtf8("namepoint"));
        namepoint->setGeometry(QRect(80, 20, 131, 31));
        xpoint = new QPlainTextEdit(Ponto);
        xpoint->setObjectName(QString::fromUtf8("xpoint"));
        xpoint->setGeometry(QRect(30, 90, 51, 31));
        label_2 = new QLabel(Ponto);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 130, 16, 16));
        ypoint = new QPlainTextEdit(Ponto);
        ypoint->setObjectName(QString::fromUtf8("ypoint"));
        ypoint->setGeometry(QRect(90, 90, 51, 31));
        label_3 = new QLabel(Ponto);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 130, 16, 16));
        createpoint = new QPushButton(Ponto);
        createpoint->setObjectName(QString::fromUtf8("createpoint"));
        createpoint->setGeometry(QRect(70, 180, 141, 32));
        tabWidget->addTab(Ponto, QString());
        Reta = new QWidget();
        Reta->setObjectName(QString::fromUtf8("Reta"));
        label_7 = new QLabel(Reta);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 20, 59, 16));
        nameline = new QPlainTextEdit(Reta);
        nameline->setObjectName(QString::fromUtf8("nameline"));
        nameline->setGeometry(QRect(80, 20, 131, 31));
        yiline = new QPlainTextEdit(Reta);
        yiline->setObjectName(QString::fromUtf8("yiline"));
        yiline->setGeometry(QRect(90, 70, 51, 31));
        label_8 = new QLabel(Reta);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 110, 16, 16));
        xiline = new QPlainTextEdit(Reta);
        xiline->setObjectName(QString::fromUtf8("xiline"));
        xiline->setGeometry(QRect(30, 70, 51, 31));
        label_9 = new QLabel(Reta);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 110, 16, 16));
        yfline = new QPlainTextEdit(Reta);
        yfline->setObjectName(QString::fromUtf8("yfline"));
        yfline->setGeometry(QRect(90, 130, 51, 31));
        label_10 = new QLabel(Reta);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 170, 16, 16));
        xfline = new QPlainTextEdit(Reta);
        xfline->setObjectName(QString::fromUtf8("xfline"));
        xfline->setGeometry(QRect(30, 130, 51, 31));
        label_11 = new QLabel(Reta);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(100, 170, 21, 16));
        createline = new QPushButton(Reta);
        createline->setObjectName(QString::fromUtf8("createline"));
        createline->setGeometry(QRect(60, 220, 141, 32));
        tabWidget->addTab(Reta, QString());
        polygon = new QWidget();
        polygon->setObjectName(QString::fromUtf8("polygon"));
        polypointlist = new QListView(polygon);
        polypointlist->setObjectName(QString::fromUtf8("polypointlist"));
        polypointlist->setGeometry(QRect(10, 10, 256, 91));
        polyxpoint = new QPlainTextEdit(polygon);
        polyxpoint->setObjectName(QString::fromUtf8("polyxpoint"));
        polyxpoint->setGeometry(QRect(10, 180, 51, 31));
        label_4 = new QLabel(polygon);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 59, 16));
        polyypoint = new QPlainTextEdit(polygon);
        polyypoint->setObjectName(QString::fromUtf8("polyypoint"));
        polyypoint->setGeometry(QRect(70, 180, 51, 31));
        addpolypoint = new QPushButton(polygon);
        addpolypoint->setObjectName(QString::fromUtf8("addpolypoint"));
        addpolypoint->setGeometry(QRect(50, 250, 141, 32));
        namepolygon = new QPlainTextEdit(polygon);
        namepolygon->setObjectName(QString::fromUtf8("namepolygon"));
        namepolygon->setGeometry(QRect(70, 130, 131, 31));
        label_5 = new QLabel(polygon);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 220, 16, 16));
        label_6 = new QLabel(polygon);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 220, 16, 16));
        createpoly = new QPushButton(polygon);
        createpoly->setObjectName(QString::fromUtf8("createpoly"));
        createpoly->setGeometry(QRect(50, 330, 141, 32));
        tabWidget->addTab(polygon, QString());
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 390, 291, 111));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        buttonplus = new QPushButton(gridLayoutWidget_2);
        buttonplus->setObjectName(QString::fromUtf8("buttonplus"));

        gridLayout_4->addWidget(buttonplus, 1, 2, 1, 1);

        buttonminus = new QPushButton(gridLayoutWidget_2);
        buttonminus->setObjectName(QString::fromUtf8("buttonminus"));

        gridLayout_4->addWidget(buttonminus, 1, 0, 1, 1);

        buttonup = new QPushButton(gridLayoutWidget_2);
        buttonup->setObjectName(QString::fromUtf8("buttonup"));

        gridLayout_4->addWidget(buttonup, 1, 1, 1, 1);

        buttondown = new QPushButton(gridLayoutWidget_2);
        buttondown->setObjectName(QString::fromUtf8("buttondown"));

        gridLayout_4->addWidget(buttondown, 2, 1, 1, 1);

        buttonleft = new QPushButton(gridLayoutWidget_2);
        buttonleft->setObjectName(QString::fromUtf8("buttonleft"));

        gridLayout_4->addWidget(buttonleft, 2, 0, 1, 1);

        buttonright = new QPushButton(gridLayoutWidget_2);
        buttonright->setObjectName(QString::fromUtf8("buttonright"));

        gridLayout_4->addWidget(buttonright, 2, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1177, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        buttonmove->setText(QApplication::translate("MainWindow", "Mover", 0, QApplication::UnicodeUTF8));
        buttonscale->setText(QApplication::translate("MainWindow", "Escalonar", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Grau", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Fy", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Fx", 0, QApplication::UnicodeUTF8));
        buttonrotate->setText(QApplication::translate("MainWindow", "Girar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Nome", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        createpoint->setText(QApplication::translate("MainWindow", "Adicionar Ponto", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Ponto), QApplication::translate("MainWindow", "Ponto", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Nome", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Xi", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Yi", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Xf", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Yf", 0, QApplication::UnicodeUTF8));
        createline->setText(QApplication::translate("MainWindow", "Adicionar Reta", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Reta), QApplication::translate("MainWindow", "Reta", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Nome", 0, QApplication::UnicodeUTF8));
        addpolypoint->setText(QApplication::translate("MainWindow", "Adicionar Ponto", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        createpoly->setText(QApplication::translate("MainWindow", "Adicionar Poligono", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(polygon), QApplication::translate("MainWindow", "Poligono", 0, QApplication::UnicodeUTF8));
        buttonplus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        buttonminus->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonup->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        buttondown->setText(QApplication::translate("MainWindow", "v", 0, QApplication::UnicodeUTF8));
        buttonleft->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        buttonright->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Window", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
