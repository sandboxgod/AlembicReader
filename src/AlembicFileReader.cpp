#include "AlembicFileReader.h"
#include "Logger.h"

#include <Alembic/AbcGeom/All.h>
#include <Alembic/AbcCoreAbstract/All.h>
#include <Alembic/AbcCoreOgawa/All.h>
#include <Alembic/Abc/ErrorHandler.h>

namespace kreationsedge {
    void TraverseScene(Alembic::AbcGeom::IObject& obj, size_t numChildren)
    {
        kreationsedge::Logger& logger = kreationsedge::Logger::getInstance();
        for (int i = 0; i < numChildren; ++i)
        {
            logger.get().info(obj.getChildHeader(i).getFullName());
            Alembic::AbcGeom::IObject child(obj, obj.getChildHeader(i).getName());

            logger.get().info("Children {} ", child.getNumChildren());
            const Alembic::AbcGeom::MetaData &md = child.getMetaData();
            logger.get().info(md.serialize());

            for (int x = 0; x < child.getNumChildren(); x++)
            {
                Alembic::AbcGeom::IObject child2(child, child.getChildHeader(x).getName());
                const Alembic::AbcGeom::MetaData &md2 = child2.getMetaData();
                if (Alembic::AbcGeom::IPolyMeshSchema::matches(md2) || Alembic::AbcGeom::ISubDSchema::matches(md2))
                {
                    logger.get().info("Found a mesh {}", child2.getName());
                }
            }
        }
    }

    void AlembicFileReader::LoadAlembic(const std::string& file)
    {
        kreationsedge::Logger& logger = kreationsedge::Logger::getInstance();

        Alembic::AbcGeom::IArchive archive(Alembic::AbcCoreOgawa::ReadArchive(), file);

        logger.get().info("Traversing archive for elements");
        Alembic::AbcGeom::IObject obj = archive.getTop();
        auto numChildren = obj.getNumChildren();
        logger.get().info("found {} children in file", numChildren);
        TraverseScene(obj, numChildren);
    }

}