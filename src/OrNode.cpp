#include "OrNode.h"


BEGIN_CGSQL_NS

OrNode::OrNode(Node* parent)
    : LogicalBase(parent)
{
}

OrNode::~OrNode()
{
}

END_CGSQL_NS
