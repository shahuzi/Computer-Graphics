#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include "bezier.h"

namespace Ui {
class Ellipse;
}

class Ellipse : public QDialog
{
    Q_OBJECT

public:
    explicit Ellipse(QWidget *parent = 0);
    ~Ellipse();
protected:
    QPixmap pix;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int LongAxis,ShortAxis;
    void DrawEllipse();

private:
    Ui::Ellipse *ui;
    QPoint CircleCenter;
private slots:
    void Clear_clicked();

};

#endif // ELLIPSE_H
