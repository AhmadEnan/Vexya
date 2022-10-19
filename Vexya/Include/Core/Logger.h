#pragma once
#include <spdlog/spdlog.h>

#include "typedefs.h"
#include "Utillity/String.h"

namespace Vexya 
{
	class Logger 
	{
	private:
		Ref<spdlog::logger> m_NativeLogger;

	public:
		Logger(const String& name, bool* success);
		Logger(const String& name);
		~Logger();


		template<typename T>
		inline void trace(const T& msg)
		{
			m_NativeLogger->trace(msg);
		}

		template<typename ...Args>
		inline void trace(const char* fmt, const Args & ...args)
		{
			m_NativeLogger->trace(fmt, args...);
		}

		template<typename T>
		inline void debug(const T& msg)
		{
			m_NativeLogger->debug(msg);
		}

		template<typename ...Args>
		inline void debug(const char* fmt, const Args & ...args)
		{
			m_NativeLogger->debug(fmt, args...);
		}

		template<typename T>
		inline void error(const T& msg)
		{
			m_NativeLogger->error(msg);
		}

		template<typename ...Args>
		inline void error(const char* fmt, const Args & ...args)
		{
			m_NativeLogger->error(fmt, args...);
		}

		template<typename T>
		inline void warning(const T& msg)
		{
			m_NativeLogger->warn(msg);
		}

		template<typename ...Args>
		inline void warning(const char* fmt, const Args & ...args)
		{
			m_NativeLogger->warn(fmt, args...);
		}

		template<typename T>
		inline void critical(const T& msg)
		{
			m_NativeLogger->critical(msg);
		}

		template<typename ...Args>
		inline void critical(const char* fmt, const Args & ...args)
		{
			m_NativeLogger->critical(fmt, args...);
		}
	};
}