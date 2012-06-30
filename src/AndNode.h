#ifndef ANDNODE_H
#define ANDNODE_H

#include "LogicalBase.h"

BEGIN_CGSQL_NS

class AndNode: public LogicalBase
{
public:
    AndNode(Node* parent = 0);
    virtual ~AndNode();
};

END_CGSQL_NS

#endif // ANDNODE_H
