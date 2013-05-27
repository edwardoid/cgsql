#include "ConceptNode.h"
#include "HasNode.h"

BEGIN_CGSQL_NS

ConceptNode::ConceptNode(Node* parent,
             const std::string& name)
    : Node(parent)
    , m_name(name)
{
}

Node::Type ConceptNode::type() const
{
    return Node::Concept;
}

bool ConceptNode::canAdd(Node::Type type) const
{
    return true;
    return Node::Logical == type || Node::Has == type;
}

void ConceptNode::setName(const std::string& name)
{
    m_name = name;
}

std::string ConceptNode::name() const
{
    return m_name;
}

void ConceptNode::setRequieredValue(const std::string& requieredValue)
{
    m_requieredValue = requieredValue;
}

std::string ConceptNode::requieredValue() const
{
    return m_requieredValue;
}

void ConceptNode::setLeft(Node*)
{
    WARNING("Trying to set left node on concept node");
}

void ConceptNode::setRight(Node*)
{
    WARNING("Trying to set right node on concept node");
}

ConceptNode::~ConceptNode()
{
}

std::string ConceptNode::toString() const
{
    return m_name + std::string(".") + m_requieredValue;
}

bool ConceptNode::accept(AbstractCalculationData* data) const
{
	bool ok = false;
	CE::piece_color c = color(&ok);
	if(!ok)
		return false;
	return data->calculate(m_name.c_str(), m_requieredValue.c_str(), c);
}

CE::piece_color ConceptNode::color(bool* ok) const
{
	const Node* p = parent();
	while(p != NULL & p->type() != Node::Has)
	{
		p = p->parent();
	}

	if(ok != NULL)
	{
		*ok = false;
	}

	if(p == NULL)
	{
		return -1;
	}

	const HasNode* has = dynamic_cast<const HasNode*>(p);
	if (NULL != has)
	{
		if(ok != NULL)
		{
			*ok = true;
		}

		return has->color() == Node::Whites ? CE::white : CE::black;
	}
	return - 1;
}


END_CGSQL_NS
