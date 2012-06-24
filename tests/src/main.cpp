#include <fstream>
#include <iostream>
#include <Query.h>
#include <QueryParser.h>
#include <RootNode.h>
#include <ConceptNode.h>

int main(int argc, char** argv)
{
	std::ifstream file("simple.cgsql");
	if(file.good())
	{
		cgsql::RootNode root;
		cgsql::ConceptNode concept;
		cgsql::Query q;
		file >> q;
        cgsql::QueryParser::parse(q.toString());
	}
}
