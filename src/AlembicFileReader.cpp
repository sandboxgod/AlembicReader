#include "AlembicFileReader.h"

#include <Alembic/AbcGeom/All.h>
#include <Alembic/AbcCoreAbstract/All.h>
#include <Alembic/AbcCoreOgawa/All.h>
#include <Alembic/Abc/ErrorHandler.h>

namespace kreationsedge {
	void TraverseScene(Alembic::AbcGeom::IObject& obj, size_t numChildren)
	{
		for (int i = 0; i<numChildren; ++i)
		{
			std::cout << obj.getChildHeader(i).getFullName() << "\n";
			Alembic::AbcGeom::IObject child(obj, obj.getChildHeader(i).getName());

			std::cout << "Children " << child.getNumChildren() << "\n";
			const Alembic::AbcGeom::MetaData &md = child.getMetaData();
			std::cout << md.serialize() << "\n";

			for (int x = 0; x<child.getNumChildren(); x++)
			{
				Alembic::AbcGeom::IObject child2(child, child.getChildHeader(x).getName());
				const Alembic::AbcGeom::MetaData &md2 = child2.getMetaData();
				if (Alembic::AbcGeom::IPolyMeshSchema::matches(md2) || Alembic::AbcGeom::ISubDSchema::matches(md2))
				{
					std::cout << "Found a mesh " << child2.getName() << "\n";
				}
			}
		}
	}

	void AlembicFileReader::LoadAlembic(const std::string& file)
	{
		Alembic::AbcGeom::IArchive archive(Alembic::AbcCoreOgawa::ReadArchive(), file);

		std::cout << "traversing archive for elements\n";
		Alembic::AbcGeom::IObject obj = archive.getTop();
		auto numChildren = obj.getNumChildren();
		std::cout << "found " << numChildren << " children in file\n";
		TraverseScene(obj, numChildren);
	}

}