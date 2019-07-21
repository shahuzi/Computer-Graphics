#include "fill.h"
#include "ui_fill.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>

#define X_pos 20
#define Y_pos 20

using namespace std;
DIRECTION direction_4[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
Fill::Fill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fill)
{
    ui->setupUi(this);
    setWindowTitle("Fill");
    this->setFixedSize(750,560);
    this->paintbool=false;
    img=QImage(500,500,QImage::Format_RGB32);
    value=qRgb(0,0,0);
    img.fill(Qt::white);
    this->setMouseTracking(true);
    this->isPressed=false;
    connect(ui->SelectFeedBtn,SIGNAL(clicked()),this,SLOT(SelectFeed_clicked()));
    connect(ui->ClearBtn,SIGNAL(clicked()),this,SLOT(Clear_clicked()));

}

Fill::~Fill()
{
    delete ui;
}

void Fill::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(X_pos,Y_pos,img);
}


int ** Fill::DrawFilled(int **image, int x, int y)
{


   FloodSeedFill(image, x, y, 0, 1) ;

    return image;
}

void Fill::FloodSeedFill(int **image, int x, int y, int old_color, int new_color)
 {
     if(image[x][y] == old_color)
     {
         image[x][y] = new_color ;
         img.setPixel(x,y,qRgb(0,0,0));
         for(int i = 0; i < 4; i++)
         {

            FloodSeedFill(image, x + direction_4[i].x_offset,y + direction_4[i].y_offset, old_color, new_color);
         }
     }
     setCursor(Qt::CustomCursor);
     this->isPressed=true;
     paintbool = false;
 }


void Fill::mousePressEvent(QMouseEvent *e)
{
    this->isPressed=true;
    startPnt=QPoint(e->pos().x()-X_pos,e->pos().y()-Y_pos);
    endPnt=QPoint(e->pos().x()-X_pos,e->pos().y()-Y_pos);
    int x=e->pos().x()-X_pos;
    int y=e->pos().y()-Y_pos;   //第一次点击截止到此处，其实什么都没干。
    if (paintbool==true)        //第二次点击进此
    {
        pnt temp;
        temp.x=x;temp.y=y;
        pnts.push_back(temp);
        int **image=new int *[500];
        for (int i=0;i<500;i++)
            image[i]=new int[500];
        for (int i=0;i<500;i++)
            for (int j=0;j<500;j++)
            {
                image[i][j]=0;  //对里面的点置0
                if (img.pixel(i,j)==qRgb(0,0,0))
                    image[i][j]=1;  //如果是黑色，置1
            }
        DrawFilled(image,temp.x,temp.y);
        delete[] image;
        update();
        }

}


void Fill::mouseMoveEvent(QMouseEvent *e)
{
   if (this->isPressed)
    {
       endPnt=QPoint(e->pos().x()-X_pos,e->pos().y()-Y_pos);
       LineStruct *Line=new LineStruct;
       Line->startPnt=startPnt;
       Line->endPnt=endPnt;
       QPainter painter(&img);
       painter.drawLine(Line->startPnt,Line->endPnt);
       painter.end();
       update();
       startPnt=endPnt;
    }
}

void Fill::mouseReleaseEvent(QMouseEvent *e)
{
    this->isPressed=false;
}


void Fill::SelectFeed_clicked()
{
     setCursor(Qt::CrossCursor);
     paintbool=true;
}

void Fill::Clear_clicked()
{

    setCursor(Qt::ArrowCursor);
    this->img.fill(Qt::white);
    paintbool=false;
    update();
}
