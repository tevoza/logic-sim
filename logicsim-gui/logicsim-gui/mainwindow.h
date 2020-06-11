#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "net.h"
#include "and.h"
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QVector>
//#include "drawline.h"

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
    void dispNodeInfo();
    bool setNodeName();
    void refreshGUI();
    void addAnd();
    void addNet();

private:

      void createActions();
      void createConnections();
      void createToolBar();

      QAction* lineAction;
      QAction* selectAction;
      QToolBar* drawingToolBar;
    Node* getNode(const int& id);
    int fetchNodeId(QString selected);
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    std::vector<Node*> my_nodes;
    std::vector<QPoint*> my_points;
    int nodeId = 0;
};
#endif // MAINWINDOW_H
