#include <fstream>
#include <iostream>
#include <Query.h>
#include <QueryParser.h>
#include <QueryPrinter.h>
#include <RootNode.h>
#include <ConceptNode.h>

int main(int argc, char** argv)
{
	std::ifstream file("simple.cgsql");
    std::ofstream out("out.cgsql");
	if(file.good())
	{
		cgsql::Query q;
		file >> q;
        q.parse();
        cgsql::QueryPrinter printer(q);
        out << printer;
	}
    file.close();
    out.close();
}
