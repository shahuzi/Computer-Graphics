#include "bezier.h"
#include "ui_bezier.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QMessageBox>
#include <QPointF>

Bezier::Bezier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bezier)
{
    ui->setupUi(this);
    this->setFixedSize(810,570);
    pix = QPixmap (500,500);
    pix.fill(Qt::white);
    this->setMouseTracking(true);
    this->setWindowTitle("Bezier");
    connect(ui->DrawBezierBtn,SIGNAL(clicked()),this,SLOT(DrawBezierBtn_clicked()));
    connect(ui->ClearBtn,SIGNAL(clicked()),this,SLOT(ClearBtn_clicked()));

}

Bezier::~Bezier()
{
    delete ui;
}

void Bezier::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(40,20,pix);
}



QPointF DeCasteljauAlgorithm(QPoint *points, int n, float u)
{

    QPointF *P=new QPointF[n];
    int j=0,k=0;
    for (j=0;j<n;j++)
    {
        P[j] = points[j];
    }
    for (k=1;k<n;k++)
    {
        for (j=0;j<n - k;j++)
        {
            P[j]= (1-u) * P[j] + u * P[j+1];
           // P[j] = (1-u) * P[j] + u * P[j+1];

        }
    }
   return P[0];
}


QPointF Bezier::CubicBezier(QPoint *points, double t)  //此方法有问题，暂不用

{
    float t_Square,t_Cubic;
    float a0,a1,a2;
    QPointF P ;
    t_Square = t * t;
    t_Cubic = t_Square * t;
    a0 = -t_Cubic + 3 * t_Square - 3 * t + 1;
    a1 = 3 * t_Cubic + 6 * t_Square + 3 * t;
    a2 = -3* t_Cubic + 3 * t_Square;

    P = a0 * points[0] + a1* points[1] + a2 * points[2] + t_Cubic * points[3];
    return P;
}

void Bezier::mousePressEvent(QMouseEvent *e)
{
    QPoint point;
    point = QPoint(e->pos().x()-40,e->pos().y()-20);
    QPainter painter(&pix);
    painter.drawEllipse(point,2,2);
    this->points.point[i++] = point;
    if (i!=1)
    {

        painter.drawLine(points.point[i - 1],points.point[i - 2]);
    }

    painter.end();
    update();

}

void Bezier::DrawBezierBtn_clicked()
{
    double t;
    QPainter painter(&pix);
    QPen pen = painter.pen();
    pen.setWidth(1);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    QPointF drawedpoint;
    for(t=0;t<=1;t+=0.001/i)
    {
        drawedpoint = DeCasteljauAlgorithm(points.point,i,t);
        painter.drawPoint(drawedpoint.x(),drawedpoint.y());
    }
    i = 0;
    painter.end();
    update();
}

void Bezier::ClearBtn_clicked()
{
    pix.fill(Qt::white);
    i = 0;
    update();

}
