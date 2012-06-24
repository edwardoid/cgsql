#ifndef CONCEPTNODE_H
#define CONCEPTNODE_H

#include "Node.h"
#include <string>


BEGIN_CGSQL_NS

class ConceptNode: public Node
{
public:
    ConceptNode(Node* parent = 0,
            const std::string& name = std::string());
    virtual ~ConceptNode();
    virtual Node::Type type() const;
    virtual bool canAdd(const Node::Type type) const;
    virtual void setName(const std::string& name);
    std::string name() const;
    void setRequieredValue(const std::string& value);
    std::string requieredValue() const;
    virtual void setLeft(Node*);
    virtual void setRight(Node*);
private:
    std::string m_requieredValue;
    std::string m_name;
};

END_CGSQL_NS

#endif // CONCEPTNODE_H 
