#include "ResultNode.h"
#include <PGNGame.h>

BEGIN_CGSQL_NS

ResultNode::ResultNode(Node* parent)
    : Node(parent)
{
    m_result = WhitesWins;
}

Node::Type ResultNode::type() const
{
    return Result; 
}

bool ResultNode::canAdd(const Node::Type type) const
{
    return true;
}

void ResultNode::setResult(Node::GameResult result)
{
    m_result = result;
}

Node::GameResult ResultNode::result() const
{
    return m_result;
}

std::string ResultNode::toString() const
{
    return Node::toString(m_result);
}

bool ResultNode::accept( const pgn::Game* game ) const
{
	if(WhitesWins == m_result) return game->result().isWhiteWin();
	if(BlacksWins == m_result) return game->result().isWhiteWin();
	if(Tie        == m_result) return game->result().isDrawn();
	return true;
}


END_CGSQL_NS
