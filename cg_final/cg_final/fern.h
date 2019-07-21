#ifndef FERN_H
#define FERN_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

using namespace std;

namespace Ui {
class Fern;
}

class Fern : public QDialog
{
    Q_OBJECT

public:
    explicit Fern(QWidget *parent = 0);
    ~Fern();
protected:
    QPixmap pix;
    void paintEvent(QPaintEvent *event);
    vector<QPointF> pointarray;

private:
    Ui::Fern *ui;
private slots:
    void GenerateFern_clicked();
    void Clear_clicked();
};

#endif // FERN_H
