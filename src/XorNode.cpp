#include "XorNode.h"


BEGIN_CGSQL_NS

XorNode::XorNode(Node* parent)
    : LogicalBase(parent)
{
}

XorNode::~XorNode()
{
}

std::string XorNode::toString() const
{
    return "XOR";
}

bool XorNode::accept(AbstractCalculationData* data) const
{
	return (left() ? left()->accept(data) : true) ^ (right() ? right()->accept(data) : true );
}

END_CGSQL_NS
