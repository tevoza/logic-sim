#ifndef NODE_H
#define NODE_H

//#include "nodeline.h"
#include <iostream>
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class NodeLine;

class Node : public QGraphicsItem
{
public:
    Node();
    enum class node_state {UNDEFINED, OFF, ON};

    private:
    node_state m_state = node_state::UNDEFINED;
    int m_id = 0;

    protected:
    int MAXINPUTS=-1;
    std::string STR_NODETYPE = "NODE";
    std::string m_name;
    std::vector<Node*> m_outputs;
    std::vector<Node*> m_inputs;
    std::vector<NodeLine*> m_outputLines;

    public:
    void set_name(const char* name);
    void set_state(const node_state& state);
    void set_id(const int& id);
    void define_node(const int& id, const char* name, const node_state& state);
    node_state get_state();
    int get_id();
    std::string get_name();
    std::string get_type_name();
    std::string mstate_to_string(node_state state);
    std::string print_info();

    bool add_output(Node *out_node);
    bool rem_output(Node *out_node);
    bool add_input(Node *in_node);
    bool rem_input(Node *in_node);
    virtual bool calc_state() = 0;
    int m_visits = 0; //times visited when calculating

    //QT INTEGRATION
private:
    friend class MainWindow   ;
public:
    bool m_pressed;
    QRectF boundingRect() const;//coords around obj
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//draw object
    void defineLine(Node *out_node);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // NODE_H
