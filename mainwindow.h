#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCamera>
#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_axWidget_OnXAfterStart();

    void on_axWidget_OnServerConnected(const QString &eventDetails);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QCamera *mCamera;
    QCamera *mCamera2;
    QVBoxLayout *mLayout1;
};

#endif // MAINWINDOW_H
