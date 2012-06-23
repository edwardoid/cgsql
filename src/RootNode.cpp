#include "RootNode.h"

BEGIN_CGSQL_NS

RootNode::RootNode()
	: Node(0)
{
}

Node::Type RootNode::type() const
{
	return Node::Root;
}

void RootNode::setHeader(Header* header)
{
	setLeft(header);
}

void RootNode::setBody(Body* body)
{
	setRight(body);
}

Header* RootNode::header() const
{
	return left();
} 

Body* RootNode::body() const
{
	return right();
}

RootNode::~RootNode()
{
}

END_CGSQL_NS