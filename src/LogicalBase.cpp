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

END_CGSQL_NS
