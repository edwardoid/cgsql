#ifndef ROOTNODE_H
#define ROOTNODE_H

#include "CGSQL.h"
#include "Node.h"

BEGIN_CGSQL_NS

typedef Node Header;
typedef Node Body;

class RootNode: public Node
{
public:
    RootNode();
    virtual ~RootNode();
    virtual Node::Type type() const;
    virtual bool canAdd(const Node::Type) const;
    void setHeader(Header* header);
    void setBody(Body* body); 
    Header* header() const;
    Body* body() const;
};

END_CGSQL_NS

#endif // ROOTNODE_H
