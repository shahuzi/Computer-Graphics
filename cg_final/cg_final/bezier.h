#ifndef BEZIER_H
#define BEZIER_H

#include <QDialog>
#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QPixmap>

struct PointStruct
{
    QPoint point[20];
};

void ComputeCoefficients(int n,int *c);
void ComputePoint(float u,QPoint *points,int n,int *c);
void DrawBezier(QPoint *points,int n);
QPointF DeCasteljauAlgorithm(QPoint *points, int n, float u);
namespace Ui {
class Bezier;
}

class Bezier : public QDialog
{
    Q_OBJECT

public:
    explicit Bezier(QWidget *parent = 0);
    ~Bezier();

protected:
    QPixmap pix;
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);
    int i =0;


private slots:
    void DrawBezierBtn_clicked();
    void ClearBtn_clicked();
private:
    Ui::Bezier *ui;
    PointStruct points;
    QPointF CubicBezier(QPoint *points,double t);
};

#endif // BEZIER_H
