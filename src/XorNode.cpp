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

bool XorNode::accept( const pgn::Game* game ) const
{
	return (left() ? left()->accept(game) : true) ^ (right() ? right()->accept(game) : true );
}

END_CGSQL_NS
