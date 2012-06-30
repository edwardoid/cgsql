#ifndef HASNODE_H
#define HASNODE_H

#include "Node.h"

BEGIN_CGSQL_NS

class HasNode: public Node
{
public:
    HasNode(Node* parent = 0);
    virtual Type type() const;
    virtual bool canAdd(const Type type) const;
    void setColor(NodeColor color);
    NodeColor color() const;
private:
    NodeColor m_color;
};

END_CGSQL_NS


#endif // HASNODE_H
