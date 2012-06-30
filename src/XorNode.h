#ifndef XORNODE_H
#define XORNODE_H

#include "LogicalBase.h"

BEGIN_CGSQL_NS

class XorNode: public LogicalBase
{
public:
    XorNode(Node* parent = 0);
    virtual ~XorNode();
};

END_CGSQL_NS

#endif // XORNODE_H
