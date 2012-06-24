#include "Query.h"
#include "Keywords.h"
#include "StringUtils.h"

BEGIN_CGSQL_NS

Query::Query()
{
}

Query::Query(const std::string& str)
    : m_queryStr(str)
{
}

Query::~Query()
{
}

std::string Query::toString() const
{
    return m_queryStr;
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

END_CGSQL_NS
