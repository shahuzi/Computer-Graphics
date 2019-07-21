#include "fern.h"
#include "ui_fern.h"
#include <time.h>
#include <stdlib.h>
#include <QString>
#define random(x) (rand()%x)
#define ROUND(d) int(floor(d+0.5))
Fern::Fern(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fern)
{
    ui->setupUi(this);
    setWindowTitle("Fern");
    this->setFixedSize(770,550);
    pix = QPixmap (500,500);
    pix.fill(Qt::white);
    connect(ui->GenarteFern,SIGNAL(clicked()),this,SLOT(GenerateFern_clicked()));
    connect(ui->Clear,SIGNAL(clicked()),this,SLOT(Clear_clicked()));
}

Fern::~Fern()
{
    delete ui;
}
void Fern::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(10,10,pix);

}

void Fern::GenerateFern_clicked()
{
    int MaxIteration = 400000;
    pix.fill(Qt::white);
    update();
    QPainter painter(&pix);
    QPen pen = painter.pen();
    pen.setColor(qRgb(29,82,24));
    pen.setWidth(2);
    painter.setPen(pen);
    QPointF StartPoint = QPointF(0,0);

     if (ui->MaxIteration->text().toInt() != 0)
    {
        MaxIteration = ui->MaxIteration->text().toInt();
    }
    double a[4] = {0, 0.85, 0.2, -0.15};
    double b[4] = {0, 0.04, -0.25, 0.28};
    double c[4] = {0, -0.04, 0.23, 0.26};
    double d[4] = {0.16, 0.85, 0.22, 0.24};
    double f[4] = {0, 1.6, 1.6, 0.44};
    double xk,yk,px,py;
    xk = StartPoint.x();
    yk = StartPoint.y();
    int RandNum;
    int index;
    int iteration = 0;
    srand((unsigned)time(NULL));

    for (iteration = 0;iteration < MaxIteration;iteration++)
    {

        RandNum = random(100);
        if (RandNum < 1)
        {
            index = 0;
            px = xk;
            py = yk;
            xk = a[index] * px + b[index] * py ;
            yk = c[index] * px + d[index] * py + f[index];

        }
        else if( RandNum < 8)
        {
            index = 3;
            px = xk;
            py = yk;
            xk = a[index] * px + b[index] * py ;
            yk = c[index] * px + d[index] * py + f[index];

        }
        else if( RandNum < 15)
        {
            index = 2;
            px = xk;
            py = yk;
            xk = a[index] * px + b[index] * py ;
            yk = c[index] * px + d[index] * py + f[index];

        }
        else
        {
            index = 1;
            px = xk;
            py = yk;
            xk = a[index] * px + b[index] * py ;
            yk = c[index] * px + d[index] * py + f[index];

        }
        StartPoint.setX((xk*45.0)+ 250 ); //x:-2.5~2.5
        StartPoint.setY(500 - (yk*45.0));  // y :0-10
        painter.drawPoint(StartPoint);
        update();
    }

}

void Fern::Clear_clicked()
{
    pix.fill(Qt::white);
    update();

}
