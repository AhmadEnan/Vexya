#pragma once
#include <Base.h>
#include <Error.h>

#include <Utillity/String.h>

namespace Vexya 
{
	enum ApplicationMode
	{
		Debug = 0, Release = 1, Shipping = 2
	};

	struct ApplicationState
	{
		ApplicationMode mode;
		bool isRunning;

		ApplicationState();
	};

	class Application 
	{
	public:

		// Default Constructor
		Application(const String& name = "Vexya Engine : instance");

		ErrorCode Init();
		ErrorCode Run();
	private:

		ApplicationState m_State; // The Current state of the application instance
		String m_ApplicationName; // The Name of the Application instance
	};
}