#pragma once

#include <Alembic/AbcCoreOgawa/All.h>
#include <Alembic/AbcCoreFactory/All.h>

class AlembicFileReader
{
public:
	AlembicFileReader() = default;

private:
	::Alembic::AbcCoreFactory::IFactory mFactory;
};

