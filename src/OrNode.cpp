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

bool OrNode::accept( const pgn::Game* game ) const
{
	return (left() ? left()->accept(game) : true) || (right() ? right()->accept(game) : true );
}


END_CGSQL_NS
