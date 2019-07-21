#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void LineBtn_triggered();
    void CircleBtn_triggered();
    void EllipseBtn_triggered();
    void FillBtn_triggered();
    void BezierBtn_triggered();
    void BSplineBtn_triggerd();
    void KochBtn_triggered();
    void MandelbrotBtn_triggered();
    void JuliaBtn_triggered();
    void FernBtn_triggered();

};

#endif // MAINWINDOW_H
