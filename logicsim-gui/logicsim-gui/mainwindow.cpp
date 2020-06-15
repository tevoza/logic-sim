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
    connect(ui->pushButtonAddOR, SIGNAL(clicked()), this, SLOT(addOr()));
    connect(ui->pushButtonAddNAND, SIGNAL(clicked()), this, SLOT(addNand()));

    connect(ui->pushButtonCalculateCircuit,SIGNAL(clicked()),this,SLOT(calc_circuit()));
    connect(ui->pushButtonSetName,SIGNAL(clicked()), this, SLOT(setNodeName()));
    connect(ui->comboBoxSource,SIGNAL(currentIndexChanged(QString)), this, SLOT(dispNodeInfo()));
    connect(ui->pushButtonConnectNodes,SIGNAL(clicked()),this, SLOT(connectNodes()));
    connect(ui->pushButtonDisconnectNodes,SIGNAL(clicked()), this, SLOT(disconnectNodes()));
    connect(ui->pushButtonClear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->pushButtonDeleteNode, SIGNAL(clicked()), this, SLOT(deleteNode()));
    connect(ui->pushButtonTest, SIGNAL(clicked()),scene,SLOT(update()));
    connect(scene, SIGNAL(changed(const QList<QRectF> &)),scene,SLOT(update()));

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
    ui->lineEditName->setText(QString::fromStdString(node->get_name()));
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

void MainWindow::clear()
{
    for (unsigned int i = 0 ; i < my_nodes.size(); i++)
    {
        delete my_nodes[i];
    }
    my_nodes.clear();
    ui->textBrowser->setText("Cleared circuit.");
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
        {
            ui->textBrowser->setText(QString::number(srcid)+" successfully connected "+QString::number(destid));
            //add lines to scene
            scene->addItem(src->m_outputLines.back());
        }
    }
    else
    {
        ui->textBrowser->setText(QString::number(destid)+" falied to add input "+QString::number(srcid));
    }
}

void MainWindow::disconnectNodes()
{
    int srcid = fetchNodeId(ui->comboBoxSource->currentText());
    int destid = fetchNodeId(ui->comboBoxDest->currentText());
    qDebug() << "attempting to disconnect "<<QString::number(srcid)<<" to "<<QString::number(destid);

    Node *src = getNode(srcid);
    Node *dest = getNode(destid);

    src->rem_output(dest);
    dest->rem_input(src);
}

void MainWindow::deleteNode()
{
    int nodeid = fetchNodeId(ui->comboBoxSource->currentText());
    qDebug() << "attempting to disconnect "<<QString::number(nodeid);

    Node *node = getNode(nodeid);   //clear inputs and outputs which point back to this node.
    if  (node == nullptr)
    {
        ui->textBrowser->setText("Failed to resolve given id "+QString::number(nodeid)+" in circuit!");
        return;
    }

    for (unsigned int i = 0; i<node->m_inputs.size(); i++)
    {
        node->m_inputs[i]->rem_output(node);
    }
    for (unsigned int i = 0; i<node->m_outputs.size(); i++)
    {
        node->m_outputs[i]->rem_input(node);
    }

    unsigned int vecid = 0; //find which vector id corresponds to given node id; very scruffy i know but im tired
    bool found = false;
    for(unsigned int i = 0; (i<my_nodes.size() && found == false); i++)
    {
        if (my_nodes[i] == node)
        {
            vecid = i;
            found = true;
        }
    }

    //delete from my_nodes
    if (found == true)
    {
        delete my_nodes[vecid];
        my_nodes[vecid] = nullptr;
        my_nodes.erase(std::remove(my_nodes.begin(), my_nodes.end(), nullptr), my_nodes.end());
        refreshGUI();
        ui->textBrowser->setText("Removed node "+QString::number(nodeid)+" from circuit!");
    }
    else
    {
        ui->textBrowser->setText("Failed to remove "+QString::number(nodeid)+" from circuit!");
    }
}

void MainWindow::addAnd()
{
    nodeId++;
    my_nodes.push_back(new And(nodeId));
    scene->addItem(my_nodes.back());
    my_nodes.back()->print_info();
    refreshGUI();
}

void MainWindow::addNand()
{
    nodeId++;
    my_nodes.push_back(new Nand(nodeId));
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

void MainWindow::addOr()
{
    nodeId++;
    my_nodes.push_back(new Or(nodeId));
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

        for(unsigned int i = 0; i<q.front()->m_outputs.size(); i++) //add this nodes outputs to queue
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
