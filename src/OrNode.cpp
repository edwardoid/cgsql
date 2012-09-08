#include "OrNode.h"


BEGIN_CGSQL_NS

OrNode::OrNode(Node* parent)
    : LogicalBase(parent)
{
}

OrNode::~OrNode()
{
}

std::string OrNode::toString() const
{
    return "OR";
}

bool OrNode::accept(AbstractCalculationData* data) const
{
	return (left() ? left()->accept(data) : true) || (right() ? right()->accept(data) : true );
}


END_CGSQL_NS
