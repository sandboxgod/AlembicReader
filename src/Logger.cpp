#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace {
  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("alembic_reader.txt", true);
}

namespace kreationsedge {
  Logger::Logger()
    : _logger("multi_sink", { console_sink, file_sink })
  {
    console_sink->set_pattern("[Log] [%^%l%$] %v");
    file_sink->set_level(spdlog::level::trace);
    _logger.set_level(spdlog::level::debug);
  }

  Logger& Logger::getInstance()
  {
    static kreationsedge::Logger logger;
    return logger;
  }

  spdlog::logger& Logger::get()
  {
    return _logger;
  }
}