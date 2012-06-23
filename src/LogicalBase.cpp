#include "LogicalBase.h"

BEGIN_CGSQL_NS

LogicalBase::LogicalBase(Node* parent)
	: Node(parent)
{
}

LogicalBase::~LogicalBase()
{
}

Node::Type LogicalBase::type() const
{
	return Node::Logical;
}

bool LogicalBase::canAdd(Node::Type type) const
{
	if( type == Node::Logical ||
	    type == Node::Concept )
		return true;
	return false;
}

END_CGSQL_NS
