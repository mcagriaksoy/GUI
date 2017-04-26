#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //DOSYA GÖSTERME LİST VİEW

    ui->setupUi(this);
    QString sPath = "/home/organic/Masaüstü/A/";
    dirmodel = new QFileSystemModel (this);
    dirmodel -> setRootPath(sPath);
    dirmodel -> setFilter(QDir::NoDotAndDotDot | QDir::Files);
 ui->listView->setModel(dirmodel);
 ui->listView->setRootIndex(dirmodel->setRootPath(sPath));

 ui->listView_2->setModel(dirmodel);
 ui->listView_2->setRootIndex(dirmodel->setRootPath(sPath));




//RESİM BOYOUT

    QPixmap pix("/home/organic/Masaüstü/A/1.png");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}





void MainWindow::on_pushButton_clicked()
{

    ui->label->setText("Success!");

}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{


    QPixmap pix(dirmodel ->fileInfo(index).absoluteFilePath());

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}


void MainWindow::on_listView_2_clicked(const QModelIndex &index)
{
    QPixmap pix(dirmodel ->fileInfo(index).absoluteFilePath());

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("/home/organic/Masaüstü/A/asd.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"INFO",file.errorString());

    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}
