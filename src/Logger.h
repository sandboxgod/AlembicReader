#pragma once

#include "spdlog/spdlog.h"

namespace kreationsedge {
  class Logger final
  {
  public:
    static Logger& getInstance();
    spdlog::logger& get();

  private:
    Logger();
    spdlog::logger _logger;
  };
}