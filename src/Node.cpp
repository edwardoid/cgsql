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

std::string Node::toString( const Node::HasAbility ability)
{
    return (ability == Yes ? "HAS" : "HASNT");
}

std::string Node::toString(const Node::NodeColor color)
{
    switch(color)
    {
        case Whites: return "WHITES";
        case Blacks: return "BLACKS";
    }
    ASSERT(false);
    return "Unknown";
}

std::string Node::toString(const Node::GameResult result)
{
    switch(result)
    {
        case WhitesWins: return "WHITES WINS";
        case BlacksWins: return "WHITES LOSES";
        case Tie:        return "TIE";
    }
    ASSERT(false);
    return "Unknown";
}

std::list<Node*> Node::childListByType( Type type, std::list<Node*>& list /*= std::list<Node*>()*/ )
{
	if (this->type() == type) list.push_back(this);
	if (m_right) m_right->childListByType(type, list);
	if (m_left) m_left->childListByType(type, list);
	
	return list;
}

bool Node::accept(const pgn::Game* game) const
{
	bool res = true;
	if (m_left) res = m_left->accept(game);
	if (m_right) res = res && m_right->accept(game);
	return res;
}


END_CGSQL_NS
