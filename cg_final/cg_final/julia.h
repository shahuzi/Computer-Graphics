#ifndef JULIA_H
#define JULIA_H

#include <QDialog>
#include <QWidget>
#include <QImage>
#include <QRgb>
#include <QPoint>
#include <QPainter>
#include <QColor>

namespace Ui {
class Julia;
}



class Julia : public QDialog
{
    Q_OBJECT

public:
    explicit Julia(QWidget *parent = 0);
    ~Julia();

private:
    Ui::Julia *ui;
protected:

    QImage img;
    QColor value;
    void paintEvent(QPaintEvent *event);
    int CalculateIteration(double zx,double zy,double cx,double cy,int MaxIteration);
    void Julia::SetColor(int x,int y,int it);
private slots:
    void GenerateJulia_clicked();
    void Clear_clicked();
};

#endif // JULIA_H
