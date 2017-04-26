#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;


private slots:


    void on_pushButton_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_listView_2_clicked(const QModelIndex &index);
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
