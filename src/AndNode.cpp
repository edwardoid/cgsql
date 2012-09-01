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


bool AndNode::accept( const pgn::Game* game ) const
{
	return (left() ? left()->accept(game) : true) && (right() ? right()->accept(game) : true );
}

END_CGSQL_NS
