#include "qviewport.h"

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
            break;
        }
    }
}

void Qviewport::updateObjects(std::vector<DisplayFileObject*> objs){
    objects = objs;
}
