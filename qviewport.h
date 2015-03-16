#ifndef QVIEWPORT_H
#define QVIEWPORT_H

#include <QWidget>
#include <QPainter>
#include "displayFile.h"
#include "objects/displayFileObject.h"
#include "objects/coordinate.h"

class QViewport : public QWidget
{
public:
	QViewport ( QWidget * parent = 0);
	virtual ~QViewport();
    void updateObjects(DisplayFileObject objs);

protected:
	void paintEvent(QPaintEvent *);
private:
	DisplayFile objects;
	QPainter painter;
};

#endif
