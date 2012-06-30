#include "HasNode.h"

BEGIN_CGSQL_NS

HasNode::HasNode(Node* parent)
    : Node(parent)
    , m_color(Node::Whites)
{
}

Node::Type HasNode::type() const
{
    return Node::Has;
}

bool HasNode::canAdd(const Node::Type type) const
{
    return true;
}


void HasNode::setColor(Node::NodeColor color)
{
    m_color = color;
}

Node::NodeColor HasNode::color() const
{
    return m_color;
}
END_CGSQL_NS
