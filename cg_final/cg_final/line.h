#ifndef LINE_H
#define LINE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include "bezier.h"

namespace Ui {
class Line;
}

class Line : public QDialog
{
    Q_OBJECT

public:
    explicit Line(QWidget *parent = 0);
    ~Line();
protected:
    QPixmap pix;
    int PointNum = 2;
    int i =0;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void DrawLine(QPoint point1,QPoint point2);
private:
    Ui::Line *ui;
    PointStruct points;

private slots:
    void ClearBtn_clicked();
};

#endif // LINE_H
