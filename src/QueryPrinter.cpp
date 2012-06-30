#include "QueryPrinter.h"

BEGIN_CGSQL_NS

QueryPrinter::QueryPrinter(const Query& q)
    : m_ast(NULL)
{
}

QueryPrinter::QueryPrinter(const AST* ast)
    : m_ast(ast)
{
}

std::ostream& operator << (std::ostream& os,
                           const QueryPrinter p)
{
    return os << "Printer";
}

END_CGSQL_NS
