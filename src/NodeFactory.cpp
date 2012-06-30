#include "NodeFactory.h"
#include "Node.h"
#include "StringUtils.h"
#include "Keywords.h"
#include "PlayerNode.h"
#include "ConceptNode.h"
#include "HasNode.h"
#include "AndNode.h"
#include "OrNode.h"
#include "XorNode.h"
#include <string.h>

BEGIN_CGSQL_NS

Node* NodeFactory::nodeFromString(const std::string& str)
{
    StringList l = StringUtils::split(str, " ");
    Node::Type possibleNodeType = Node::Root;
    Node *leftChild = 0,
         *rightChild = 0;
    for(StringList::const_iterator i = l.begin();
        i != l.end();
        ++i)
    {
        if(*i == WHITES ||
           *i == BLACKS)
        {
            possibleNodeType = Node::Color;
        }
        else if((*i == HAS    ||
                 *i == HASNT) &&
                 possibleNodeType == Node::Color)
        {
            possibleNodeType = Node::Has;
        }
        else if(strIsPlayerName(*i) &&
                possibleNodeType == Node::Color)
        {
            possibleNodeType = Node::Player;
        }
        else if(strIsConcept(*i))
        {
            StringList cl = StringUtils::split(*i, CONCEPT_DELIMETER);
            ConceptNode* c = new ConceptNode();
            c->setName(*(cl.begin()));
            c->setRequieredValue(*cl.rend());
            if(leftChild)
                rightChild = c;
            else
                leftChild = c;
        }
        else if(strIsLogic(*i))
        {
            possibleNodeType = Node::Logical;
        }
        else 
        {
            SYNTAX_ERROR(*i, "Unknown keyword");
            return NULL;
        }
    }
    switch(possibleNodeType)
    {
        case Node::Player:
        {
            ASSERT(l.size() == 2);
            PlayerNode* node = new PlayerNode();
            if(*l.begin() == WHITES)
                node->setColor(Node::Whites);
            else if(*l.rend() == BLACKS)
                node->setColor(Node::Blacks);
            else
            {
                ASSERT(false);
                return NULL;
            }
            return node;
        }
 
        case Node::Has:
        {
            ASSERT(l.size() == 2);
            HasNode* node = new HasNode();
            if(*l.begin() == WHITES)
                node->setColor(Node::Whites);
            else if(*l.begin() == BLACKS)
                node->setColor(Node::Blacks);
            else
            {

                ASSERT(false);
                return NULL;
            }
            return node;
        }

        case Node::Logical:
        {
            std::string logicalStr;
            for(StringList::const_iterator it = l.begin();
                it != l.end();
                ++it)
            {
                if(strIsLogic(*it))
                {
                    logicalStr = *it;
                    break;
                } 
            }
            Node* logical = logicNodeByStr(logicalStr);
            ASSERT(logical);
            if(leftChild)
                logical->setLeft(leftChild);
            if(rightChild)
                logical->setRight(rightChild);
            return logical;
        }
    }
    return NULL;
}

bool NodeFactory::strIsPlayerName(const std::string& str)
{
    if(str.size() < 3) return false;
    return str[0] == PLAYER_NAME_QTT &&
           str[str.size() -1] == PLAYER_NAME_QTT;
}

bool NodeFactory::strIsConcept(const std::string& str)
{
    StringList l = StringUtils::split(str, CONCEPT_DELIMETER);
    return l.size() == 2;
}

bool NodeFactory::strIsLogic(const std::string& str)
{
    return (str == AND_K) ^
           (str == OR_K)  ^
           (str == XOR_K);
}

Node* NodeFactory::logicNodeByStr(const std::string& str)
{
    if(str == AND_K) return new AndNode();
    if(str == OR_K)  return new OrNode();
    if(str == XOR_K) return new XorNode();
    return NULL;
}

END_CGSQL_NS

