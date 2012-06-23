#include "QueryParser.h"

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

AST* QueryParser::parse(const std::string& str, AST* ast)
{
	return ast;
}

AST* QueryParser::ast() const
{
	return m_root;
}

END_CGSQL_NS
