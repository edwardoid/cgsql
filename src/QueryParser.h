#ifndef QUERYPARSER_H
#define QUERYPARSER_H

#include "CGSQL.h"
#include "RootNode.h"
#include <string>

BEGIN_CGSQL_NS

typedef RootNode AST;

class QueryParser
{
public:
    QueryParser(const std::string& str = std::string(),
            AST* root = new AST());
    ~QueryParser();
    static AST* parse(const std::string& str, AST* root = new AST(), const int level = 0);
    AST* ast() const;
private:
    #ifdef DEBUG_PARSING_LEVELS
    static void printLevelOffset(const int level);
    #endif
private:
    AST* m_root;
    std::string m_q;
};

END_CGSQL_NS


#endif // QUERYPARSER_H
