#ifndef CIRCLE_H
#define CIRCLE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>



namespace Ui {
class Circle;
}

class Circle : public QDialog
{
    Q_OBJECT

public:
    explicit Circle(QWidget *parent = 0);
    ~Circle();
protected:
    QPixmap pix;
    bool drawpointbool;
    int CircleRadius = 0;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void DrawCircle();

private:
    Ui::Circle *ui;
    QPoint CircleCenter;

private slots:
    void ClearBtn_clicked();
};

#endif // CIRCLE_H
