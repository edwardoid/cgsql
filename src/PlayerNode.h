#ifndef PLAYERNODE_H
#define PLAYERNODE_H

#include "Node.h"

BEGIN_CGSQL_NS

class PlayerNode: public Node
{
public:
    PlayerNode(Node* parent);
    virtual ~PlayerNode();
    virtual Node::Type type() const;
    virtual bool canAdd(const Node::Type type) const;
    void setName(const std::string& name);
    std::string name() const;
    void setColor(Node::NodeColor color);
    Node::NodeColor color() const;
private:
    std::string m_name;
    Node::NodeColor m_color;
};

END_CGSQL_NS
#endif // PLAYERNODE_H
