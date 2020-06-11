#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "input.h"
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
    bool dispNodeInfo();
    bool setNodeName();
    void refreshGUI();
    void connectNodes();

    void addAnd();
    void addNet();
    void addInput();

private:
    Node* getNode(const int& id);
    int fetchNodeId(QString selected);
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    std::vector<Node*> my_nodes;
    int nodeId = 0;
};
#endif // MAINWINDOW_H
