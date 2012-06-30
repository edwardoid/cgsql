#ifndef NODEFACTORY_H
#define NODEFACTORY_H

#include "CGSQL.h"


BEGIN_CGSQL_NS

class Node;

class NodeFactory
{
public:
    static
    Node* nodeFromString(const std::string& str);

private:
    static
    Node* strContainsColorInformation(const std::string& str);

    static
    bool strIsPlayerName(const std::string& str);

    static 
    bool strIsConcept(const std::string& str);

    static 
    bool strIsLogic(const std::string& str);

    static
    Node* logicNodeByStr(const std::string& str);
};

END_CGSQL_NS

#endif // NODEFACTORY_H
