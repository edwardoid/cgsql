#include "XorNode.h"


BEGIN_CGSQL_NS

XorNode::XorNode(Node* parent)
    : LogicalBase(parent)
{
}

XorNode::~XorNode()
{
}

END_CGSQL_NS
