#include "koch.h"
#include "ui_koch.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include "math.h"
#include <QPixmap>
#include <QMessageBox>
#include <QPointF>
#include <QComboBox>

Koch::Koch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Koch)
{
    ui->setupUi(this);
    this->drawpointbool=false;
    this->setFixedSize(742,560);
    pix = QPixmap (500,500);
    pix.fill(Qt::white);
    this->setMouseTracking(true);
    this->setWindowTitle("Koch");

  //  connect(ui->SelectPointsBtn,SIGNAL(clicked()),this,SLOT(SelectPointBtn_clicked()));
    connect(ui->KochBtn,SIGNAL(clicked()),this,SLOT(KochBtn_clicked()));
    connect(ui->ClearBtn,SIGNAL(clicked()),this,SLOT(ClearBtn_clicked()));
}

Koch::~Koch()
{
    delete ui;
}

int numofkochpoint = 0;
void Koch::KochCalculate(QPointF point1,QPointF point2 ,int n)
{
    double dx = (double)(point2.x() - point1.x());
    double dy = (double)(point2.y() - point1.y());

    if (n == 0)
    {
        return;
    }
    double dx1 = dx / 3.0;
    double dy1 = dy / 3.0;
    double dx2 = dx * 2.0 / 3.0;
    double dy2 = dy * 2.0 / 3.0;

    QPointF P1 ;
    QPointF P2 ;
    P1.setX(point1.x() + dx1);
    P1.setY(point1.y() + dy1);
    P2.setX(point1.x() + dx2);
    P2.setY(point1.y() + dy2);
    double mid_dx = 0.5 * dx;
    double mid_dy = 0.5 * dy;

    QPointF mid_point ;
    mid_point.setX(point1.x() + mid_dx);
    mid_point.setY(point1.y() + mid_dy);


    double x11 = -dy;
    double y11 = dx;
    double dx3 = (double)(sqrt(3.0)/6.0) * x11;
    double dy3 = (double)(sqrt(3.0)/6.0) * y11;

    QPointF P3 ;
    P3.setX(mid_point.x() + dx3);
    P3.setY(mid_point.y() + dy3);



    KochCalculate(point1,P1,n-1);   //每递归一次再存入坐标，这点极为重要
    pointarray.push_back(P1);
    KochCalculate(P1,P3,n-1);
    pointarray.push_back(P3);
    KochCalculate(P3,P2,n-1);
    pointarray.push_back(P2);
    KochCalculate(P2,point2,n-1);
    pointarray.push_back(point2);

}
void Koch::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(10,10,pix);

}

void Koch::mousePressEvent(QMouseEvent *e)
{
    QPoint point;
    point = QPoint(e->pos().x()-10, e->pos().y()-10 );
    QPainter painter(&pix);
    painter.drawEllipse(point,2,2);
    this->points.point[i++] = point;
    painter.end();
    update();
    if ( i == PointNum )
    {

       i = 0;

     }

}




void Koch::KochBtn_clicked()
{
    int n= 0;
    int index;
    i = 0;
    QPainter painter(&pix);
    n = ui->IterNum->text().toInt();
    index = ui->Direction->currentIndex();

    if (index == 0)                                         //亮点，精心设计
    {
        pointarray.push_back(points.point[1]);
        KochCalculate(points.point[1],points.point[0],n);
        long int size =pointarray.size();
        for(int k =0;k<size-1;k++)
        {
            painter.drawLine(pointarray[k],pointarray[k+1]);

        }
    }
    else
    {
        pointarray.push_back(points.point[0]);
        KochCalculate(points.point[0],points.point[1],n);
        long int size =pointarray.size();
        for(int k =0;k<size;k++)
        {
            painter.drawPoint(pointarray[k]);

        }

    }

    drawpointbool = false;
    pointarray.clear();  //绘画完成后清空数据
    painter.end();
    update();
}

void Koch::ClearBtn_clicked()
{
    drawpointbool = false;
    pix.fill(Qt::white);
    i = 0;
    ui->IterNum->clear();
    pointarray.clear();
    update();

}


