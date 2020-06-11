#include "input.h"

Input::Input(const int& id)
{
    this->set_state(node_state::OFF);
    this->set_id(id);
    MAXINPUTS=-1;
    STR_NODETYPE = "INPUT";
}

bool Input::calc_state()
{
    std::cout << "Error: State of input always predefined - can not calc state";
    return false;
}

void Input::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (this->get_state() == node_state::OFF)
        this->set_state(node_state::ON);
    else
        this->set_state(node_state::OFF);

    update();
    QGraphicsItem::mousePressEvent(event);
}
