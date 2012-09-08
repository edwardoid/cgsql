#include "AndNode.h"


BEGIN_CGSQL_NS

AndNode::AndNode(Node* parent)
    : LogicalBase(parent)
{
}

AndNode::~AndNode()
{
}

std::string AndNode::toString() const
{
    return "AND";
}


bool AndNode::accept(AbstractCalculationData* data) const
{
	return (left() ? left()->accept(data) : true) && (right() ? right()->accept(data) : true );
}

END_CGSQL_NS
