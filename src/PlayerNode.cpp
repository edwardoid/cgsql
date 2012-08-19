#include "PlayerNode.h"


BEGIN_CGSQL_NS

PlayerNode::PlayerNode(Node* parent)
    : Node(parent)
    , m_name()
    , m_color(Node::Whites)
{
}

PlayerNode::~PlayerNode()
{
}

Node::Type PlayerNode::type() const
{
    return Node::Player;
}

bool PlayerNode::canAdd(const Node::Type type) const
{
    return type == Node::Root;
}

void PlayerNode::setName(const std::string& name)
{
    m_name = name;
}

std::string PlayerNode::name() const
{
    return m_name;
}

void PlayerNode::setColor(Node::NodeColor color)
{
    m_color = color;
}

Node::NodeColor PlayerNode::color() const
{
    return m_color;
}

std::string PlayerNode::toString() const
{
    return Node::toString(m_color) += m_name;
}

END_CGSQL_NS
