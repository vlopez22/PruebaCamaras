#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>

static QList<QCameraInfo> cameras;
static int control = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cameras = QCameraInfo::availableCameras();
    //foreach (const QCameraInfo &cameraInfo, cameras) {
    QCameraViewfinder *mCameraViewfinder = new QCameraViewfinder(this);
    mLayout1 = new QVBoxLayout;
    mCamera = new QCamera(QCameraInfo(cameras[0]));
    mCamera2 = new QCamera(QCameraInfo(cameras[1]));
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout1->setMargin(0);
    mLayout1->addWidget(mCameraViewfinder);
    ui->widget->setLayout(mLayout1);
    mCamera->start();
    double i=cameras[1].position();
    ui->lineEdit->setText(QString::number(i));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    delete mLayout1;
    if(control==0){
        mLayout1 = new QVBoxLayout;
        QCameraViewfinder *mCameraViewfinder = new QCameraViewfinder(this);
        mCamera2->setViewfinder(mCameraViewfinder);
        mLayout1->setMargin(0);
        mLayout1->addWidget(mCameraViewfinder);
        ui->widget->setLayout(mLayout1);
        mCamera2->start();
        control=1;
        mCamera->stop();
    }else{
        mLayout1 = new QVBoxLayout;
        QCameraViewfinder *mCameraViewfinder = new QCameraViewfinder(this);
        mCamera->setViewfinder(mCameraViewfinder);
        mLayout1->setMargin(0);
        mLayout1->addWidget(mCameraViewfinder);
        ui->widget->setLayout(mLayout1);
        mCamera->start();
        control=0;
        mCamera2->stop();
    }
}

void MainWindow::on_axWidget_OnXAfterStart()
{
    ui->axWidget->dynamicCall("connectToServer(\"192.168.0.157\")");
}

void MainWindow::on_axWidget_OnServerConnected(const QString &eventDetails)
{
    ui->axWidget->dynamicCall("login(\"17vlopez\",\"qwerty\")");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->axWidget->dynamicCall("call(\"10vlopez\")");
    //ui->axWidget->setLayout(mLayout1);
}
