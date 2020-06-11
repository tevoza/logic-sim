#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(ui->pushButtonAddAND,SIGNAL(clicked()), this, SLOT(addAnd()));
    connect(ui->pushButtonAddWire,SIGNAL(clicked()), this, SLOT(addNet()));
    connect(ui->pushButtonAddInput,SIGNAL(clicked()), this, SLOT(addInput()));


    connect(ui->pushButtonSetName,SIGNAL(clicked()), this, SLOT(setNodeName()));
    connect(ui->comboBoxSource,SIGNAL(currentIndexChanged(QString)), this, SLOT(dispNodeInfo()));
    connect(ui->pushButtonConnectNodes,SIGNAL(clicked()),this, SLOT(connectNodes()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::dispNodeInfo()
{
    qDebug() << "changed!";
    QString namestring = ui->comboBoxSource->currentText();
    int id = fetchNodeId(namestring);
    Node *node = getNode(id);
    if (node == nullptr)
    {
        qDebug() << "Error, no id found matching node";
        return false;
    }
    QString info = QString::fromStdString(node->print_info());
    ui->textBrowser->setPlainText(info);
}

bool MainWindow::setNodeName()
{
    QString namestring = ui->comboBoxSource->currentText();
    int id = fetchNodeId(namestring);
    Node *node = getNode(id);
    if (node == nullptr)
    {
        qDebug() << "Error, no id found matching node";
        return false;
    }
    QString NewName = ui->lineEditName->text();
    QByteArray array = NewName.toLocal8Bit();
    char* buffer = array.data();
    node->set_name(buffer);
    refreshGUI();
    return true;
}

int MainWindow::fetchNodeId(QString selected)
{
    //regular expressions because why not.
    QRegularExpression re("(^\\[)\\d*");
    QRegularExpressionMatch match = re.match(selected);
    QString matched;

    if (match.hasMatch()) {
        matched = match.captured(0);
        matched.remove(QChar('['), Qt::CaseInsensitive);
        qDebug() <<matched;
    }
    return matched.toInt();
}

void MainWindow::refreshGUI()
{
    ui->comboBoxSource->clear();
    ui->comboBoxDest->clear();
    ui->textBrowser->clear();
    QString namestring = ui->comboBoxSource->currentText();
    //int id = fetchNodeId(namestring);

    for (unsigned int i = 0 ; i < my_nodes.size(); i++)
    {
        QString item = "["+QString::number(my_nodes[i]->get_id())+"]";
        item += "["+QString::fromStdString(my_nodes[i]->get_type_name())+"] ";
        item += QString::fromStdString(my_nodes[i]->get_name());
        //item += QString::fromStdString(my_nodes[i]->mstate_to_string(my_nodes[i]->get_state()))+")"; tmi
        ui->comboBoxSource->addItem(item);
        ui->comboBoxDest->addItem(item);
    }
    ui->lineEditName->setText("lol");
    this->dispNodeInfo();
}

void MainWindow::connectNodes()
{
    int srcid = fetchNodeId(ui->comboBoxSource->currentText());
    int destid = fetchNodeId(ui->comboBoxDest->currentText());
    qDebug() << "attempting to connect "<<QString::number(srcid)<<" to "<<QString::number(destid);

    Node *src = getNode(srcid);
    Node *dest = getNode(destid);

    if ((src->add_output(dest)) == false)
    {
        ui->textBrowser->setText(QString::number(srcid)+"falied to add output "+QString::number(destid));
    }
    if ((dest->add_input(src)) == false)
    {
        ui->textBrowser->setText(QString::number(destid)+"falied to add input "+QString::number(destid));
    }
    //reverse conn if failed later.
}

void MainWindow::addAnd()
{
    nodeId++;
    my_nodes.push_back(new And(nodeId));
    scene->addItem(my_nodes.back());
    my_nodes.back()->print_info();
    refreshGUI();
}

void MainWindow::addNet()
{
    nodeId++;
    my_nodes.push_back(new Net(nodeId));
    scene->addItem(my_nodes.back());
    my_nodes.back()->print_info();
    refreshGUI();
}

void MainWindow::addInput()
{
    nodeId++;
    my_nodes.push_back(new Input(nodeId));
    scene->addItem(my_nodes.back());
    my_nodes.back()->print_info();
    refreshGUI();
}

Node *MainWindow::getNode(const int &id)
{
    unsigned int i = 0;
    bool found = false;
    while((i < my_nodes.size()) && (found == false))
    {
        if (my_nodes[i]->get_id() == id)
        {
            return my_nodes[i];
        }
        i++;
    }
    return nullptr;
}

