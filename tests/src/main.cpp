#include <fstream>
#include <iostream>
#include <Query.h>


int main(int argc, char** argv)
{
	std::ifstream file("simple.cgsql");
	if(file.good())
	{
		cgsql::Query q;
		file >> q;
		std::cout << q;
	}
}
