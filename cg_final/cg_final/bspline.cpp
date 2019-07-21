#include "bspline.h"
#include "ui_bspline.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QMessageBox>
#include <QPointF>

Bspline::Bspline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bspline)
{
    ui->setupUi(this);
    this->drawpointbool=true;
    this->setFixedSize(720,580);
    pix = QPixmap (500,500);
    pix.fill(Qt::white);
    this->setMouseTracking(true);
    this->setWindowTitle("Bspline");
    connect(ui->CubicBsplineBtn,SIGNAL(clicked()),this,SLOT(CubicBsplineBtn_clicked()));
    connect(ui->ClearBtn,SIGNAL(clicked()),this,SLOT(ClearBtn_clicked()));

}

Bspline::~Bspline()
{
    delete ui;
}
void Bspline::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(10,10,pix);
}



void Bspline::mousePressEvent(QMouseEvent *e)
{

    if (drawpointbool == true)
    {
        QPoint point;
        point = QPoint(e->pos().x()-10,e->pos().y()-10);
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

}


void Bspline::CubicBsplineBtn_clicked()
{
    double u = 0;
    int j = 0;
    float u_Square,u_Cubic;
    float alpha = 0.16666667;
    QPainter painter(&pix);
    QPen pen = painter.pen();
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    QPointF *point = new QPointF[4];
    QPointF drawedpoint;
    for(j=0;j<=i-4;j++)
    {
        for(u=0;u<=1;u+=0.001)
        {
            u_Square = u * u;
            u_Cubic = u* u_Square;
            point[0] = (-u_Cubic + 3 * u_Square -3 * u + 1) * points.point[j];
            point[1] = (3 * u_Cubic - 6 * u_Square + 4) * points.point[j+1];
            point[2] = (-3 * u_Cubic + 3 * u_Square + 3 * u + 1) * points.point[j+2];
            point[3] = u_Cubic * points.point[j+3];
            drawedpoint = alpha *(point[0] + point[1]+ point[2]+ point[3]);
            painter.drawPoint(drawedpoint.x(),drawedpoint.y());
        }
    }
    drawpointbool = true;
    i = 0;
    painter.end();
    update();

}

void Bspline::ClearBtn_clicked()
{
    drawpointbool = true;
    pix.fill(Qt::white);
    i = 0;
    update();

}
