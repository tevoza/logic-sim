#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Node : public QGraphicsItem
{
public:
    Node();
    bool m_pressed;
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

    public:
    void set_name(const char* name);
    void set_state(const node_state& state);
    void set_id(const int& id);
    void define_node(const int& id, const char* name, const node_state& state);
    node_state get_state();
    int get_id();
    std::string get_name();
    void print_info();

    bool add_output(Node *out_node);
    bool rem_output(Node *out_node);
    bool add_input(Node *in_node);
    bool rem_input(Node *in_node);
    virtual bool calc_state() = 0;
};

#endif // NODE_H