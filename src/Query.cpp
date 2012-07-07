#include "Query.h"
#include "Keywords.h"
#include "StringUtils.h"
#include "Node.h"
#include "RootNode.h"
#include "QueryParser.h"

BEGIN_CGSQL_NS

Query::Query()
    : m_queryStr()
    , m_ast(0)
{
}

Query::Query(const std::string& str)
    : m_queryStr(str)
    , m_ast(0)
{
}

Query::~Query()
{
    if(m_ast)
        delete m_ast;
}

std::string Query::toString() const
{
    return m_queryStr;
}

void Query::clear()
{
    m_queryStr.erase();
}

bool Query::parse(const std::string& queryStr)
{
    if(queryStr.size() > 2)
       m_queryStr = queryStr;
    if(m_ast)
        delete m_ast;
    m_ast = new AST();
    m_ast = QueryParser::parse(m_queryStr, m_ast);
    return m_ast != 0;
}

std::istream& operator >> (std::istream& is, Query& q)
{
    std::string tmp;
    while(getline(is, tmp))
    {
        size_t commentSymbolPos = tmp.find_first_of(COMMENT);
        if(commentSymbolPos != std::string::npos)
        {
            #ifdef DEBUG_COMMENTS
            std::cout << "Removed comment: "
                      << tmp.substr(commentSymbolPos + 1) << std::endl;
            #endif
            tmp = tmp.substr(0, commentSymbolPos);
        }
        tmp = StringUtils::trim(tmp);
        if(tmp.size() < 1)
            continue;
        q.m_queryStr += tmp + " ";
    }
    return is;
}

std::ostream& operator << (std::ostream& os, const Query& q)
{
    return os << q.m_queryStr;
}

AST* Query::ast() const
{
    return m_ast;
}

END_CGSQL_NS
