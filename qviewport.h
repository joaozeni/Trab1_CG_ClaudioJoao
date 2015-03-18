#ifndef QVIEWPORT_H
#define QVIEWPORT_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include "displayFileObject.h"
#include "coordinate.h"

class Qviewport : public QWidget
{
    Q_OBJECT
public:
    explicit Qviewport(QWidget *parent = 0);
    ~Qviewport();
    void updateObjects(std::vector<DisplayFileObject*> objs);

protected:
    void paintEvent(QPaintEvent *);

private:
    std::vector<DisplayFileObject*> objects;
    //QPainter painter;

signals:

public slots:
};

#endif // QVIEWPORT_H
