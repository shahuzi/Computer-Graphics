#ifndef FILL_H
#define FILL_H

#include <QDialog>
#include <QWidget>
#include <QPoint>
#include <vector>
#include <QPixmap>
#include <QImage>
#include <stack>
using namespace std;

namespace Ui {
class Fill;
}

typedef struct LineStruct
{
    QPoint startPnt;
    QPoint endPnt;
}LineStruct;


typedef struct pnt
{
    int x;
    int y;
}pnt;
typedef struct tagDIRECTION
{
    int x_offset;
    int y_offset;
}DIRECTION;





class Fill : public QDialog
{
    Q_OBJECT

public:
    explicit Fill(QWidget *parent = 0);
    ~Fill();

private slots:
    void SelectFeed_clicked();
    void Clear_clicked();

protected:
    bool paintbool;
    bool isPressed;
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void FloodSeedFill(int **image, int x, int y, int old_color, int new_color) ;
    QPoint startPnt,endPnt;
    void paintEvent(QPaintEvent *event);
    QImage img;
    QRgb value;
    vector<pnt> pnts;

private:
    Ui::Fill *ui;
    int ** Fill::DrawFilled(int **image, int x, int y);

};

#endif // Fill_H


