#include "mandelbrot.h"
#include "ui_mandelbrot.h"

Mandelbrot::Mandelbrot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mandelbrot)
{
    ui->setupUi(this);
    this->setWindowTitle("Mandelbrot");
    img=QImage(500,500,QImage::Format_RGB32);
    img.fill(Qt::white);
    connect(ui->GenarteMandelbrot,SIGNAL(clicked()),this,SLOT(GenerateMandelbrot_clicked()));
    connect(ui->Clear,SIGNAL(clicked()),this,SLOT(Clear_clicked()));
}

Mandelbrot::~Mandelbrot()
{
    delete ui;
}

void Mandelbrot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(10,10,img);
}

int Mandelbrot::CalculateIteration(double cx, double cy, double zx, double zy, int MaxIteration)
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

void Mandelbrot::GenerateMandelbrot_clicked()
{
    double cx,cy,zx = 0.0 ,zy = 0.0;

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

    for(x = 0,cx = Min;x <500;cx+= delta,x++)
    {

        for(y = 0,cy = Min;y<500;cy+=delta,y++)
        {
            it = CalculateIteration(cx,cy,zx,zy,MaxIteration);
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

void Mandelbrot::SetColor(int x,int y,int it)
{
    value=QColor::fromHsv(it,255,125);
    this->img.setPixelColor(x,y,value);


}

void Mandelbrot::Clear_clicked()
{
    img.fill(Qt::white);
    ui->MaxIteration->clear();
    update();
}
