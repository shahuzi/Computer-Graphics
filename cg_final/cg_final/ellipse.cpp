#include "ellipse.h"
#include "ui_ellipse.h"
#include <QPixmap>

#define ROUND(a) ((int)(a+0.5))
Ellipse::Ellipse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ellipse)
{
    ui->setupUi(this);
    setWindowTitle("Ellipse");
    this->setFixedSize(800,660);
    pix = QPixmap (650,650);
    pix.fill(Qt::white);
    connect(ui->ClearBtn,SIGNAL(clicked()),this,SLOT(Clear_clicked()));
}

Ellipse::~Ellipse()
{
    delete ui;
}

void Ellipse::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(10,10,pix);
}


void Ellipse::mousePressEvent(QMouseEvent *e)
{
    QPainter painter(&pix);
    painter.setPen(Qt::red);
    CircleCenter = QPoint(e->pos().x()-10,e->pos().y()-10);
    painter.drawEllipse(CircleCenter,1,1);
    update();

}

void Ellipse::DrawEllipse()
{
    QPainter painter(&pix);
    int xCenter=0,yCenter=0,Rx2=0,Ry2=0,twoRx2=0,twoRy2=0;
    int Rx=0,Ry=0;
    xCenter = CircleCenter.x();
    yCenter = CircleCenter.y();
    Rx = LongAxis;
    Ry = ShortAxis;
    Rx2 = Rx*Rx;
    Ry2 = Ry*Ry;
    twoRx2 = 2 * Rx2;
    twoRy2 = 2 * Ry2;
    int p = 0,x = 0,y = Ry,px = 0,py = twoRx2 * y;
    painter.drawPoint(QPoint(xCenter + x,yCenter + y));
    painter.drawPoint(QPoint(xCenter - x,yCenter + y));
    painter.drawPoint(QPoint(xCenter + x,yCenter - y));
    painter.drawPoint(QPoint(xCenter - x,yCenter - y));
    update();
    p = ROUND(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while(px<py)
    {

        x++;
        px += twoRy2;
        if(p<0)
        {
            p += Ry2 + px;
        }
        else
        {
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        painter.drawPoint(QPoint(xCenter + x,yCenter + y));
        painter.drawPoint(QPoint(xCenter - x,yCenter + y));
        painter.drawPoint(QPoint(xCenter + x,yCenter - y));
        painter.drawPoint(QPoint(xCenter - x,yCenter - y));
    }
    update();
    p = ROUND(Ry2 *(x+0.5)*(x+0.5) + Rx2*(y-1)*(y-1) - Rx2 * Ry2 );
   while(y>0)
    {
        y--;
        py -= twoRx2;
        if(p>0)
        {
            p += Rx2 - py;
        }
        else
        {
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        painter.drawPoint(QPoint(xCenter + x,yCenter + y));
        painter.drawPoint(QPoint(xCenter - x,yCenter + y));
        painter.drawPoint(QPoint(xCenter + x,yCenter - y));
        painter.drawPoint(QPoint(xCenter - x,yCenter - y));
    }
    update();

}

void Ellipse::mouseReleaseEvent(QMouseEvent *event)
{
    DrawEllipse();
}
void Ellipse::mouseMoveEvent(QMouseEvent *event)
{
    QPoint EndPoint;
    EndPoint = QPoint(event->pos().x()-10,event->pos().y()-10);
    int dx,dy;
    dx = EndPoint.x() - CircleCenter.x();
    dy = EndPoint.y() - CircleCenter.y();
    LongAxis = dx;
    ShortAxis = dy;

}
void Ellipse::Clear_clicked()
{
    pix.fill(Qt::white);
    update();
}
