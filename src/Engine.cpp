#include "AlembicFileReader.h"
#include "Logger.h"

#include <iostream>

int main(int argc, const char * argv[])
{
    if (argc < 2)
    {
        std::cout << "alembicviewer <filename>" << std::endl;
        system("pause");
        return 1;
    }

    kreationsedge::Logger& logger = kreationsedge::Logger::getInstance();
    logger.get().info("alembicviewer {}", argv[1]);
    kreationsedge::AlembicFileReader fileReader;
    const std::string file(argv[1]);
    fileReader.LoadAlembic(file);

    system("pause");
    return 0;
}
