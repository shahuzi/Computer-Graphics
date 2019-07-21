#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "fill.h"
#include "bezier.h"
#include "bspline.h"
#include "koch.h"
#include "mandelbrot.h"
#include "julia.h"
#include "fern.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("HomePage");
    setWindowIcon(QIcon("cg_final.ico"));
    connect(ui->LineBtn, SIGNAL(triggered()), this, SLOT(LineBtn_triggered()));
    connect(ui->CircleBtn,SIGNAL(triggered()),this,SLOT(CircleBtn_triggered()));
    connect(ui->EllipseBtn,SIGNAL(triggered()),this,SLOT(EllipseBtn_triggered()));
    connect(ui->FillBtn,SIGNAL(triggered()),this,SLOT(FillBtn_triggered()));
    connect(ui->BezierBtn,SIGNAL(triggered()),this,SLOT(BezierBtn_triggered()));
    connect(ui->BSplineBtn,SIGNAL(triggered()),this,SLOT(BSplineBtn_triggerd()));

    connect(ui->KochBtn,SIGNAL(triggered()),this,SLOT(KochBtn_triggered()));
    connect(ui->MandelbrotBtn,SIGNAL(triggered()),this,SLOT(MandelbrotBtn_triggered()));
    connect(ui->JuliaBtn,SIGNAL(triggered()),this,SLOT(JuliaBtn_triggered()));
    connect(ui->FernBtn,SIGNAL(triggered()),this,SLOT(FernBtn_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LineBtn_triggered()
{
    Line LineWindow(this);
    LineWindow.exec();

}

void MainWindow::CircleBtn_triggered()
{
    Circle CircleWindow(this);
    CircleWindow.exec();
}

void MainWindow::EllipseBtn_triggered()
{
    Ellipse EllipseWindow(this);
    EllipseWindow.exec();
}

void MainWindow::FillBtn_triggered()
{
    Fill FillWindow(this);
    FillWindow.exec();

}

void MainWindow::BezierBtn_triggered()
{
    Bezier BezierWindow(this);
    BezierWindow.exec();

}

void MainWindow::BSplineBtn_triggerd()
{
    Bspline BsplineWindow(this);
    BsplineWindow.exec();

}

void MainWindow::KochBtn_triggered()
{
    Koch KochWindow(this);
    KochWindow.exec();
}

void MainWindow::MandelbrotBtn_triggered()
{
    Mandelbrot MandelbrotWindow(this);
    MandelbrotWindow.exec();
}

void MainWindow::JuliaBtn_triggered()
{
    Julia JuliaWindow(this);
    JuliaWindow.exec();
}

void MainWindow::FernBtn_triggered()
{
    Fern FernWindow(this);
    FernWindow.exec();
}






