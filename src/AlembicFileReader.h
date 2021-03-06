#pragma once

#include <Alembic/AbcCoreOgawa/All.h>
#include <Alembic/AbcCoreFactory/All.h>

namespace kreationsedge {

  class AlembicFileReader final
  {
  public:
    AlembicFileReader() = default;
    void LoadAlembic(const std::string& file);

  private:
    ::Alembic::AbcCoreFactory::IFactory mFactory;
  };

} // namespace kreationsedge