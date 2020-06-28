#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mywindow.h"
#include<QMediaPlayer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),player(nullptr)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);
    player=new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/mus1.mp3"));
    player->setVolume(30);
    player->play();
    scene=new Mywindow(nullptr);
    (*scene).update();
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        this->close();
        scene->show();
        scene->start_timer();
        player->pause();
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap(":/originalbackground.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}

