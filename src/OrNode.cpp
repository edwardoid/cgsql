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

END_CGSQL_NS
