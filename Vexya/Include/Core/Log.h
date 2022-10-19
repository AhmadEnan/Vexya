#pragma once
#include <Core/Logger.h>
#include <error.h>

namespace Vexya
{
	class Log 
	{
	private:
		static std::shared_ptr<Logger> s_EngineLogger;
		// static Logger s_RendererLogger; // to be used
		static std::shared_ptr<Logger> s_InstanceLogger;

	public:
		static ErrorCode initialize();

		// Getters
		static std::shared_ptr<Logger>& EngineLogger() { return s_EngineLogger; }
		static std::shared_ptr<Logger>& InstanceLogger() { return s_InstanceLogger; }
	};
}

// Core log macros
#define VX_CORE_TRACE(...)    ::Vexya::Log::EngineLogger()->trace(__VA_ARGS__)
#define VX_CORE_INFO(...)     ::Vexya::Log::EngineLogger()->info(__VA_ARGS__)
#define VX_CORE_WARN(...)     ::Vexya::Log::EngineLogger()->warn(__VA_ARGS__)
#define VX_CORE_ERROR(...)    ::Vexya::Log::EngineLogger()->error(__VA_ARGS__)
#define VX_CORE_CRITICAL(...) ::Vexya::Log::EngineLogger()->critical(__VA_ARGS__)

// Client log macros
#define VX_TRACE(...)         ::Vexya::Log::InstanceLogger()->trace(__VA_ARGS__)
#define VX_INFO(...)          ::Vexya::Log::InstanceLogger()->info(__VA_ARGS__)
#define VX_WARN(...)          ::Vexya::Log::InstanceLogger()->warn(__VA_ARGS__)
#define VX_ERROR(...)         ::Vexya::Log::InstanceLogger()->error(__VA_ARGS__)
#define VX_CRITICAL(...)      ::Vexya::Log::InstanceLogger()->critical(__VA_ARGS__)
