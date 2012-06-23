#include "Query.h"
#include "Keywords.h"

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

std::istream& operator >> (std::istream& is, Query& q)
{
	std::string tmp;
	while(getline(is, tmp))
	{
		q.m_queryStr += tmp;
	}
	return is;
}

std::ostream& operator << (std::ostream& os, const Query& q)
{
	return os << q.m_queryStr;
}

END_CGSQL_NS
