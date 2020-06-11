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
    connect(ui->pushButtonAddXOR, SIGNAL(clicked()), this, SLOT(addXor()));

    connect(ui->pushButtonCalculateCircuit,SIGNAL(clicked()),this,SLOT(calc_circuit()));
    connect(ui->pushButtonSetName,SIGNAL(clicked()), this, SLOT(setNodeName()));
    connect(ui->comboBoxSource,SIGNAL(currentIndexChanged(QString)), this, SLOT(dispNodeInfo()));
    connect(ui->pushButtonConnectNodes,SIGNAL(clicked()),this, SLOT(connectNodes()));
}

MainWindow::~MainWindow()
{
    delete ui;
//    for (unsigned int i = 0 ; i < my_nodes.size(); i++)
//        delete my_nodes[i]
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

    if ((dest->add_input(src)) == true) //if dest node accepts src as input. add_input is more likely to fail, so we check that first.
    {
        if ((src->add_output(dest)) == false)
        {
            ui->textBrowser->setText(QString::number(srcid)+"falied to add output "+QString::number(destid));
            dest->rem_input(src);
        }
        else
            ui->textBrowser->setText(QString::number(srcid)+" successfully connected "+QString::number(destid));
    }
    else
    {
        ui->textBrowser->setText(QString::number(destid)+" falied to add input "+QString::number(srcid));
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

void MainWindow::addXor()
{
    nodeId++;
    my_nodes.push_back(new Xor(nodeId));
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

void MainWindow::calc_circuit()
{
    //set all non-input nodes to UNDEFINED. Set all visits to 0
    //also check if there are any floating nodes. i.e non-input nodes with no inputs are floating
    //add input nodes to a queue to start off from
    std::queue<Node*> q;
    unsigned int MAX_VISITS = 5;
    for (unsigned int i = 0 ; i < my_nodes.size(); i++)
    {
        //visits 0 and state to undefined.
        my_nodes[i]->m_visits = 0;
        if (my_nodes[i]->STR_NODETYPE != "INPUT")
        {
            my_nodes[i]->set_state(Node::node_state::UNDEFINED);
            if (my_nodes[i]->m_inputs.size() == 0) //check for floating node
            {
                ui->textBrowser->setText("Error: Floating node found at node "+QString::number(my_nodes[i]->get_id()));
                return;
            }
        }
        else
        {
            qDebug()<<"Adding Input Node "+QString::number(my_nodes[i]->get_id())+" to queue.Total: "+QString::number(q.size());
            q.push(my_nodes[i]);
        }
    }

    while (q.size()>0)
    {
        q.front()->m_visits++;
        qDebug() << "Visiting node "<<QString::number(q.front()->get_id());
        if (q.front()->get_state() == Node::node_state::UNDEFINED)//calc state if not defined.
        {
            q.front()->calc_state();
        }

        for(int i = 0; i<q.front()->m_outputs.size(); i++) //add this nodes outputs to queue
        {
            q.push(q.front()->m_outputs[i]);
        }

        if (q.front()->get_state() == Node::node_state::UNDEFINED)//add this node to queue as well if still not defined.
        {
            if (q.front()->m_visits <= MAX_VISITS)
            {
                q.push(q.front());//add this item again to the back
            }
            else
                qDebug()<<"MAX VISITS RACHED";
        }
        q.pop();
    }
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

