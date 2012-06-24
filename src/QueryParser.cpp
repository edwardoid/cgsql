#include "QueryParser.h"
#include "StringUtils.h"
#include <iostream>
BEGIN_CGSQL_NS


QueryParser::QueryParser(const std::string& str, AST* ast)
    : m_q(str)
    , m_root(ast)
{
    if(str.size() > 0)
        parse(str, ast);
}

QueryParser::~QueryParser()
{
}

AST* QueryParser::parse(const std::string& str, AST* ast, const int level)
{
    #ifdef DEBUG_PARSING_LEVELS
    if(level < 1)
        std::cout << "Parsing:" << std::endl << str;
    #endif
    if(str.size() < 2) return ast;
    size_t b = std::string::npos,
           e = std::string::npos,
           oldE = 0;
    std::string tmp = str;
    while(str.size() > 2)
    {
        tmp = StringUtils::extract(tmp, b, e, '(', ')');
        if(tmp.size() < 2)
            break;
        
        #ifdef DEBUG_PARSING_LEVELS
        printLevelOffset(level);
        std::cout << "|" <<std::endl;
        printLevelOffset(level);
        std::cout<< "\\_" << tmp << std::endl;
        #endif
        
        if(b == e || b == std::string::npos)
        {
            break;
        }
        parse(tmp, ast, level + 1);
        oldE += e;
        tmp = str.substr(oldE);
    }
    return ast;
}

AST* QueryParser::ast() const
{
    return m_root;
}

#ifdef DEBUG_PARSING_LEVELS
void QueryParser::printLevelOffset(const int level)
{
    int i = 0;
    while(i++ < level)
        std::cout << "|    ";
}

#endif // DEBUG_PARSING_LEVELS

END_CGSQL_NS
