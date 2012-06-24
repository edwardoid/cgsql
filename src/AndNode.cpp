#include "AndNode.h"


BEGIN_CGSQL_NS

AndNode::AndNode(Node* parent)
    : LogicalBase(parent)
{
}

AndNode::~AndNode()
{
}

END_CGSQL_NS
