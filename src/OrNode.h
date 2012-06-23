#ifndef ORNODE_H
#define ORNODE_H

#include "LogicalBase.h"

BEGIN_CGSQL_NS

class OrNode: public LogicalBase
{
public:
	OrNode(Node* parent);
	virtual ~OrNode();
};

END_CGSQL_NS

#endif // ORNODE_H
