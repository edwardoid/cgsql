#ifndef LOGICALBASE_H
#define LOGICALBASE_H

#include "Node.h"

BEGIN_CGSQL_NS

class LogicalBase: public Node
{
public:
	LogicalBase(Node* parent);
	virtual ~LogicalBase();
	virtual Node::Type type() const;
	virtual bool canAdd(Node::Type type) const;
};

END_CGSQL_NS

#endif // LOGICALBASE_H
