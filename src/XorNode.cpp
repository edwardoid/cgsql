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

END_CGSQL_NS
