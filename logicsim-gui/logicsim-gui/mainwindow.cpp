#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
//    connect((mainWindow->toolBarButton)[0],SIGNAL(clicked()),this,SLOT(newFile()));
    connect(ui->pushButtonAddAND,SIGNAL(clicked()), this, SLOT(addAnd()));
    connect(ui->pushButtonAddWire,SIGNAL(clicked()), this, SLOT(addNet()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addAnd()
{
    my_nodes.push_back(new And());
    scene->addItem(my_nodes.back());
}

void MainWindow::addNet()
{
    my_nodes.push_back(new Net());
    scene->addItem(my_nodes.back());
}

