#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "net.h"
#include "and.h"
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    public slots:
    void addAnd();
    void addNet();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QVector<Node*> my_nodes;

};
#endif // MAINWINDOW_H
