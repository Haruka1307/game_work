#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QMediaPlayer>
#include"mywindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void playmusic();
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QMediaPlayer*player;
    Mywindow*scene;
};

#endif // MAINWINDOW_H
