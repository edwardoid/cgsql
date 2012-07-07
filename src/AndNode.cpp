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

END_CGSQL_NS
