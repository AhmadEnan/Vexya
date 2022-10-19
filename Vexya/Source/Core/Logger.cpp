#include <Core/Logger.h>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Vexya 
{

	// todo : remove code duplication
	Logger::Logger(const String& name, bool* success)
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(("Vexya_" + name + ".log").GetBuffer(), true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");


		m_NativeLogger = std::make_shared<spdlog::logger>(name.GetSTDString(), begin(logSinks), end(logSinks));

		if (m_NativeLogger.get() != nullptr)
		{
			*success = true;
		}
		else return;

		spdlog::register_logger(m_NativeLogger);
		m_NativeLogger->set_level(spdlog::level::trace);
		m_NativeLogger->flush_on(spdlog::level::trace);
	}

	Logger::Logger(const String& name)
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(("Vexya_" + name + ".log").GetBuffer(), true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");


		m_NativeLogger = std::make_shared<spdlog::logger>(name.GetSTDString(), begin(logSinks), end(logSinks));
		spdlog::register_logger(m_NativeLogger);
		m_NativeLogger->set_level(spdlog::level::trace);
		m_NativeLogger->flush_on(spdlog::level::trace);
	}

	Logger::~Logger()
	{
		// none
	}

}