#include "QueryPrinter.h"
#include "RootNode.h"

BEGIN_CGSQL_NS

QueryPrinter::QueryPrinter(const Query& q)
    : m_ast(q.ast())
{
    m_ast = q.ast();
}

QueryPrinter::QueryPrinter(const AST* ast)
    : m_ast(ast)
{
}

std::ostream& operator << (std::ostream& os,
                           const QueryPrinter& p)
{
    if(!p.m_ast) return os;

    os << "[\n";
    p.printNode(os, p.m_ast->header());
    os << "]\n";
    if(p.m_ast->body())
        p.printNode(os, p.m_ast->body());
    return os;
}

std::ostream& QueryPrinter::printNode(std::ostream& os,
                                      const Node* node) const
{
    ASSERT(0 != node);
    os << " (";

    if(node->type() != Node::Logical)
        os << node->toString();
    if(node->type() == Node::Has)
        os << "( ";
    if(node->left())
        printNode(os, node->left());

    if(node->type() == Node::Logical)
        os << node->toString();
    if(node->right())
        printNode(os, node->right());
    if(node->type() == Node::Has)
        os << ") ";
    os << ") ";
    return os;
}

END_CGSQL_NS
