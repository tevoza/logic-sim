#include "and.h"

And::And()
{
    this->set_state(node_state::UNDEFINED);
    MAXINPUTS=-1;
    STR_NODETYPE = "AND";
}

bool And::calc_state()
{
    if (m_inputs.size()<2)
    {
        std::cout<<"Error: "<<m_name<<"("<<this->get_id()<<")requires at least 2 inputs."<<std::endl;
        this->set_state(node_state::OFF);
        return false;
    }

    bool offFound = false;

    for (int unsigned i = 0;i<m_inputs.size(); i++ )
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Warning: "<<this->get_id()<<" calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                offFound = true;
                break;
            case node_state::OFF:
                offFound = true;
                break;
        }
    }

    if (offFound == true)
    {
        this->set_state(node_state::OFF);
        return true;
    }
    else
    {
        this->set_state(node_state::ON);
        return true;
    }
}

QRectF And::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void And::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if (m_pressed)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::green);
    }
    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}

void And::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void And::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}