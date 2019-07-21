#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <QDialog>
#include <QWidget>
#include <QImage>
#include <QRgb>
#include <QPoint>
#include <QPainter>
#include <QColor>

namespace Ui {
class Mandelbrot;
}

class Mandelbrot : public QDialog
{
    Q_OBJECT

public:
    explicit Mandelbrot(QWidget *parent = 0);
    ~Mandelbrot();

protected:
    QImage img;
    QColor value;
    void paintEvent(QPaintEvent *event);
    int CalculateIteration(double zx,double zy,double cx,double cy,int MaxIteration);
    void SetColor(int x,int y,int it);
private:
    Ui::Mandelbrot *ui;

private slots:
    void GenerateMandelbrot_clicked();
    void Clear_clicked();
};

#endif // MANDELBROT_H
