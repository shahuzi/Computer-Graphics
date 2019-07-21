#include "julia.h"
#include "ui_julia.h"
#include "math.h"

Julia::Julia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Julia)
{
    ui->setupUi(this);
    this->setWindowTitle("Julia");
    img=QImage(500,500,QImage::Format_RGB32);
    img.fill(Qt::white);
    connect(ui->GenarteJulia,SIGNAL(clicked()),this,SLOT(GenerateJulia_clicked()));
    connect(ui->Clear,SIGNAL(clicked()),this,SLOT(Clear_clicked()));
}

Julia::~Julia()
{
    delete ui;
}

void Julia::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(10,10,img);
}

void Julia::GenerateJulia_clicked()
{
    double cx,cy,zx = 0.0 ,zy = 0.0;
    bool ok;

    int it = 0;
    double Max = 1.5;
    double Min = -1.5;
    int x,y;

    double delta = (Max - Min) / 500.0;
    int MaxIteration = 256;
    if(ui->MaxIteration->text().toInt() != 0)
    {
        MaxIteration = ui->MaxIteration->text().toInt();
    }

    cx = ui->c_Real->text().toDouble(&ok);
    cy = ui->c_Image->text().toDouble(&ok);
    for(x = 0,zx = Min;x <500;zx+= delta,x++)
    {

        for(y = 0,zy = Min;y<500;zy+=delta,y++)
        {
            it = CalculateIteration(zx,zy,cx,cy,MaxIteration);
            if (it == MaxIteration)
            {
                this->img.setPixel(x,y,Qt::white);

            }
            else
            {

                SetColor(x,y,it*10%255);
            }
        }
    }
    update();


}

int Julia::CalculateIteration(double zx, double zy, double cx, double cy, int MaxIteration)
{
    int it = 0;
    double px,py;
    while((zx * zx + zy * zy) <= 4.0 && (it < MaxIteration) )            //收敛的点
    {
        px = zx;
        py = zy;
        zx = px * px - py * py + cx;
        zy = 2 * px * py + cy;
        it++;
    }
    return it;
}

void Julia::SetColor(int x,int y,int it)
{
    value=QColor::fromHsv(it,255,125);
    this->img.setPixelColor(x,y,value);
}

void Julia::Clear_clicked()
{
    img.fill(Qt::white);
    ui->c_Image->clear();
    ui->c_Real->clear();
    ui->MaxIteration->clear();
    update();
}
