#ifndef KOCH_H
#define KOCH_H

#include <QDialog>
#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QPixmap>
#include <vector>
using namespace std;
#include "bezier.h"
#include <QPointF>
namespace Ui {
class Koch;
}

struct Point2D
{
    double x;
    double y;
};
class Koch : public QDialog
{
    Q_OBJECT

public:
    explicit Koch(QWidget *parent = 0);
    ~Koch();

private:
    Ui::Koch *ui;
    PointStruct points;
    vector<QPointF> pointarray;

protected:
    QPixmap pix;
    bool drawpointbool;
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);
    int i =0;
    int PointNum  = 2;
    void KochCalculate(QPointF point1,QPointF point2,int n );


private slots:
   // void SelectPointBtn_clicked();
    void KochBtn_clicked();
    void ClearBtn_clicked();
};

#endif // KOCH_H
