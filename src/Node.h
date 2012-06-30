#ifndef NODE_H
#define NODE_H

#include "CGSQL.h"

BEGIN_CGSQL_NS

class Node
{
public:
    typedef enum
    {
        Root = 1,
        Player,
        Color,
        Result,
        Has,
        Logical,
        Concept
    } Type;

    typedef enum
    {
        Whites = 0,
        Blacks
    } NodeColor;
public:
    Node(Node* parent = 0);
    virtual void setParent(Node* parent);
    virtual Node* parent() const;
    virtual Type type() const = 0;
    virtual void setLeft(Node* left);
    virtual void setRight(Node* right);
    virtual Node* left() const;
    virtual Node* right() const;
    virtual bool canAdd(const Type type) const = 0;
    virtual ~Node();
private:
    Node* m_parent;
    Node* m_left;
    Node* m_right;
};

END_CGSQL_NS

#endif // NODE_H
