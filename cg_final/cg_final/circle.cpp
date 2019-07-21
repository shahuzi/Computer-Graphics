#include "circle.h"
#include "ui_circle.h"
#include <QPixmap>
#include "line.h"
Circle::Circle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Circle)
{
    ui->setupUi(this);
    setWindowTitle("Circle");
    drawpointbool = true;
    this->setFixedSize(800,660);
    pix = QPixmap (650,650);
    pix.fill(Qt::white);
    connect(ui->ClearBtn,SIGNAL(clicked()),this,SLOT(ClearBtn_clicked()));
}

Circle::~Circle()
{
    delete ui;
}


void Circle::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(10,10,pix);
}

void Circle::mousePressEvent(QMouseEvent *e)
{
    QPainter painter(&pix);
    painter.setPen(Qt::red);
    QPoint point;
    point = QPoint(e->pos().x()-10,e->pos().y()-10);
    CircleCenter = point;
    painter.drawEllipse(point,1,1);
    update();
}

void Circle::DrawCircle()
{
        int xCenter = CircleCenter.x();
        int yCenter = CircleCenter.y();
        int y = CircleRadius, p = 1 - CircleRadius,x = 0;
        QPainter painter(&pix);
        painter.drawPoint(QPoint(xCenter + x,yCenter + y));
        painter.drawPoint(QPoint(xCenter - x,yCenter + y));
        painter.drawPoint(QPoint(xCenter + x,yCenter - y));
        painter.drawPoint(QPoint(xCenter - x,yCenter - y));

        painter.drawPoint(QPoint(xCenter + y,yCenter + x));
        painter.drawPoint(QPoint(xCenter - y,yCenter + x));
        painter.drawPoint(QPoint(xCenter + y,yCenter - x));
        painter.drawPoint(QPoint(xCenter - y,yCenter - x));
        update();
        while(x<y)
        {

            x++;
            if(p<0)
            {
                p+=2*x+1;
            }
            else
            {
                y--;
                p+=2*(x-y)+1;
            }
            painter.drawPoint(QPoint(xCenter + x,yCenter + y));
            painter.drawPoint(QPoint(xCenter - x,yCenter + y));
            painter.drawPoint(QPoint(xCenter + x,yCenter - y));
            painter.drawPoint(QPoint(xCenter - x,yCenter - y));

            painter.drawPoint(QPoint(xCenter + y,yCenter + x));
            painter.drawPoint(QPoint(xCenter - y,yCenter + x));
            painter.drawPoint(QPoint(xCenter + y,yCenter - x));
            painter.drawPoint(QPoint(xCenter - y,yCenter - x));
        }
        painter.end();
        update();
}
void Circle::mouseReleaseEvent(QMouseEvent *event)
{
    DrawCircle();

}

void Circle::mouseMoveEvent(QMouseEvent *event)
{

    QPoint EndPoint;
    EndPoint = QPoint(event->pos().x()-10,event->pos().y()-10);
    int dx,dy;
    dx = EndPoint.x() - CircleCenter.x();
    dy = EndPoint.y() - CircleCenter.y();
    CircleRadius = (int)(sqrt(dx * dx + dy * dy));

}
void Circle::ClearBtn_clicked()
{
    pix.fill(Qt::white);
    update();

}
