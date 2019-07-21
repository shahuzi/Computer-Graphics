#ifndef BSPLINE_H
#define BSPLINE_H

#include <QDialog>
#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QPixmap>
#include "bezier.h"
namespace Ui {
class Bspline;
}



class Bspline : public QDialog
{
    Q_OBJECT

public:
    explicit Bspline(QWidget *parent = 0);
    ~Bspline();
protected:
    QPixmap pix;
    bool drawpointbool;
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);
    int i =0;

private:
    Ui::Bspline *ui;
    PointStruct points;

private slots:
    void CubicBsplineBtn_clicked();
    void ClearBtn_clicked();

};

#endif // BSPLINE_H
