#include "qviewport.h"
#include <iostream>

Qviewport::Qviewport(QWidget *parent) : QWidget(parent)
{

}

Qviewport::~Qviewport()
{

}

void Qviewport::paintEvent(QPaintEvent *){
    //QRect region = pe->rect();
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
//    painter.begin(this);
//    painter.setBrush(QBrush(QColor(255.0, 255.0, 255.0)));
    //std::vector<DisplayFileObject*> objs = objects->getObjects();
    //std::vector<DisplayFileObject*>::iterator obj = objects->begin();
    for(int i = 0; i < objects.size(); i++){
        DisplayFileObject * obj = objects.at(i);
        std::string type = obj->getType();
        if(type == "point"){
            Coordinate * c = obj->getCoordinates().at(0);
            painter.drawPoint( c->x(), c->y());
        }
        else if(type == "line"){
            std::vector<Coordinate*> c = obj->getCoordinates();
            painter.drawLine( c.at(0)->x(), c.at(0)->y(), c.at(1)->x(), c.at(1)->y());
        }
        else{
            std::vector<Coordinate*> c = obj->getCoordinates();
            for(int j = 0; j < c.size()-1; j++){
                painter.drawLine( c.at(j)->x(), c.at(j)->y(), c.at(j+1)->x(), c.at(j+1)->y());
            }
            painter.drawLine( c.at(c.size()-1)->x(), c.at(c.size()-1)->y(), c.at(0)->x(), c.at(0)->y());
        }
    }
}

void Qviewport::updateObjects(std::vector<DisplayFileObject*> objs){
    objects = objs;
}
