#include "QueryParser.h"
#include "StringUtils.h"
#include "Keywords.h"
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

AST* QueryParser::parse(const std::string& str,
                           AST* ast,
                           const int level)
{
    if(NULL == ast)
        ast = new AST();
 
    #ifdef DEBUG_PARSING_LEVELS
    if(level < 1)
        std::cout << "Parsing:" << std::endl << str;
    #endif
 
    if(str.size() < 2) return NULL;
    size_t beg = std::string::npos,
           end = std::string::npos;

    std::string header,
                body;
    
    header = StringUtils::extract(str,
                                  beg,
                                  end,
                                  HEADER_BEGIN,
                                  HEADER_END);
    if(header.size() < 2)
    {
        SYNTAX_ERROR("No header in query", header);
        return NULL;
    }

    std::cout << "\nParsing header: " << header;
    Header* h = subParse(header, 1);
    Body* b = NULL;
    
    body = str.substr(end);
    
    if(body.size() < 2)
    {
        WARNING("Body is empty");
    }
    else
        b = subParse(body, 1);

    
    if(h != NULL)
    {
        ast->setHeader(h);
        ast->setBody(b);
    }
    else
        return NULL;

    return ast;

    
}

Node* QueryParser::subParse(const std::string& q,
                            const int level)
{
    std::string str = q;
    if(str.size() < 2)
    {
        ERROR("Empty sub-query");
        return NULL;
    }
    size_t b = 0,
           e = std::string::npos,
           oldE = 0,
           nodeStrBeg = 0,
           nodeStrEnd = 0;
    std::string tmp = str;
    Node* node = NULL;
    Node* left = NULL;
    Node* right = NULL;
    int childsCount = 0;
    while(str.size() > 2)
    {
        tmp = StringUtils::extract(tmp,
                                   b,
                                   e,
                                   BEGIN,
                                   END);
        if(tmp.size() < 2 || b == std::string::npos) break;
        
        #ifdef DEBUG_PARSING_LEVELS
        printLevelOffset(level);
        std::cout << "|" <<std::endl;
        printLevelOffset(level);
        std::cout<< "\\_" << tmp << std::endl;
        #endif
        
        if(b == e || b == std::string::npos) break;
        ++childsCount;
        if(childsCount > 2)
        {
            SYNTAX_ERROR("Unexcepted sub-query", tmp);
            return NULL;
        }
        Node* child = subParse(tmp, level + 1);
        if(left) right = child;
        else left = child;
        oldE += e;
        str.erase(b, e);
        tmp = str;
    }
    /*
        Creating node and binding children
    */
    if(node)
    {
        node->setLeft(left);
        node->setRight(right);
    }
    return node;
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
