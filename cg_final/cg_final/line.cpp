#include "line.h"
#include "ui_line.h"
#include <QPixmap>
#include "math.h"
#include <QMouseEvent>

Line::Line(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Line)
{
    ui->setupUi(this);
    setWindowTitle("Line");
    this->setFixedSize(666,530);
    pix = QPixmap (500,500);
    pix.fill(Qt::white);
    connect(ui->ClearBtn,SIGNAL(clicked()),this,SLOT(ClearBtn_clicked()));

}

Line::~Line()
{
    delete ui;
}

void Line::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(10,10,pix);

}

void Line::mousePressEvent(QMouseEvent *e)
{

    QPainter painter(&pix);
    painter.setPen(Qt::red);
    QPoint point;
    point = QPoint(e->pos().x()-10,e->pos().y()-10);
    painter.drawEllipse(point,1,1);
    this->points.point[i++] = point;
    painter.end();
    update();
    if(i==PointNum )
    {
        DrawLine(points.point[0],points.point[1]);
         i = 0;
    }


}
void Line::DrawLine(QPoint point1,QPoint point2)
{
    int Start_X,Start_Y,End_X,End_Y;
    Start_X = point1.x();
    Start_Y = point1.y();
    End_X   = point2.x();
    End_Y   = point2.y();
    if ((abs(End_Y-Start_Y))<=(abs(End_X-Start_X)))  //斜率绝对值小于1
       {
           int Detla_Y=abs(End_Y-Start_Y);
           int Detla_X=abs(End_X-Start_X);
           if (Start_X>End_X)                       //如果起点比终点大，则交换
           {
               int temp;
               temp=Start_X;Start_X=End_X;End_X=temp;
               temp=Start_Y;Start_Y=End_Y;End_Y=temp;
           }
           int p=Detla_Y*2-Detla_X;                //P0
           QPainter painter(&pix);
           painter.drawPoint(QPoint(Start_X,Start_Y));   //画点，并修正坐标系为常用方式
           int yk=Start_Y;
           for (int i=Start_X+1;i<=End_X;i++)
           {
               if (p>=0)
               {
                   p=p+2*Detla_Y-2*Detla_X;
                   if(End_Y>=Start_Y)   //判断yk是递增还是递减，即判断斜率正负
                   {
                       yk++;
                   }
                   else
                   {
                       yk--;
                   }
               }
               else
               {
                   p=p+2*Detla_Y;
               }
               painter.drawPoint(QPoint(i,yk));
           }
           painter.end();
       }
       else
       {
           int Detla_Y=abs(End_Y-Start_Y);
           int Detla_X=abs(End_X-Start_X);
           if (Start_Y>End_Y)
           {
               int temp;
               temp=Start_X;Start_X=End_X;End_X=temp;
               temp=Start_Y;Start_Y=End_Y;End_Y=temp;
           }
           int p=Detla_X*2-Detla_Y;
           QPainter painter(&pix);
           painter.drawPoint(QPoint(Start_X,Start_Y));
           int xk=Start_X;
           for (int i=Start_Y+1;i<=End_Y;i++)
           {
               if (p>=0)
               {
                   p=p+2*Detla_X-2*Detla_Y;
                   if(End_X>=Start_X)
                   {
                       xk++;
                   }
                   else
                   {
                       xk--;
                   }
               }
               else
               {
                   p=p+2*Detla_X;
               }
               painter.drawPoint(QPoint(xk,i));
           }
           painter.end();
       }
       update();

}


void Line::ClearBtn_clicked()
{
    pix.fill(Qt::white);
    update();

}
