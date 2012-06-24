#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <istream>
#include <CGSQL.h>

BEGIN_CGSQL_NS

class Query
{
public:
    Query();
    Query(const std::string& str);
    std::string toString() const;
    friend std::istream& operator >> (std::istream& is, Query& q);
    friend std::ostream& operator << (std::ostream& os, const Query& q);
    ~Query();
protected:
private:
    std::string m_queryStr;
};

END_CGSQL_NS

#endif // QUERY_H
