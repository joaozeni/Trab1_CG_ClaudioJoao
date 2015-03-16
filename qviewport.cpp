#include "qviewport.h"
#include "libcg/curva.h"

QWindow::QViewport ( QWidget * parent ) : QWidget(parent)
{
}

QWindow::~QViewport()
{
}

void QWindow::paintEvent(QPaintEvent * ){
    painter.begin(this);
    painter.setBrush(QBrush(QColor(255.0, 255.0, 255.0)));
    std::vector<DisplayFileObject>::iterator obj = objects.begin();
    while(obj != obj.end()){
        string type = obj.getType();
        if(type == "point"){
        	Coordinate c = obj.getCoordinates();
        	painter.drawPoint( c.x(), c.y());
        }
        else if(type == "line"){
        	Coordinate c[2] = obj.getCoordinates();
        	painter.drawLine( c[0].x(), c[0].y(), c[1].x(), c[1].y());
        }
        else{}
    }
}

void updateObjects(DisplayFileObject objs){
	objects = objs;
}

// void QWindow::drawLine(diplayFileObject* obj){
// 	painter.begin(this);
// 	painter.setBrush(QBrush(QColor(255.0, 255.0, 255.0)));
// 	Coordinate c[2] = obj.getCoordinates();
// 	painter.drawLine( c[0].x(), c[0].y(), c[1].x(), c[1].y());
// }

// void QWindow::drawPoint(Objeto* obj){
// 	painter.begin(this);
// 	painter.setBrush(QBrush(QColor(255.0, 255.0, 255.0)));
// 	Coordinate c = obj.getCoordinates();
// 	painter.drawPoint( c.x(), c.y());
// }
