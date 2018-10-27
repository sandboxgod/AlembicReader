//#include <Windows.h>
//#include <gl/GLU.h>

#include "AlembicFileReader.h"

#include <iostream>

int main(int argc, const char * argv[])
{
	if (argc < 2)
	{
		std::cout << "alembicviewer <filename>" << std::endl;
		system("pause");
		return 1;
	}

	std::cout << "alembicviewer <hi>" << argv[1] << std::endl;
	kreationsedge::AlembicFileReader fileReader;
	const std::string file(argv[1]);
	fileReader.LoadAlembic(file);
	system("pause");
    return 0;
}

