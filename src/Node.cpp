#include "Node.h"
#include "Debug.h"

BEGIN_CGSQL_NS

Node::Node(Node* parent)
    : m_parent(NULL)
    , m_left(NULL)
    , m_right(NULL)
{
    setParent(parent);
}

void Node::setParent(Node* parent)
{
    m_parent = parent;
}

Node* Node::parent() const
{
    return m_parent;
}


void Node::setLeft(Node* left)
{
    m_left = left;
}

void Node::setRight(Node* right)
{
    m_right = right;
}

Node* Node::left() const
{
    return m_left;
}

Node* Node::right() const
{
    return m_right;
}

Node::~Node()
{
    if(m_left)
        delete m_left;
    if(m_right)
        delete m_right;
}

END_CGSQL_NS
