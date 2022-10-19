#include <Core/Application.h>
#include <Core/Log.h>

// #include <algorithm>
// #include <chrono>
// #include <iostream>
// #include <vector>
// using namespace std;
// using namespace std::chrono;
#include "Utillity/Instrumentor.h"

namespace Vexya 
{
	ApplicationState::ApplicationState()
	{
		mode = (ApplicationMode)VX_APP_MODE;
	}

	Application::Application(const String& name)
	{
		m_ApplicationName = name;
		m_State = ApplicationState();
	}

	ErrorCode Application::Init()
	{
		VX_PROFILE_FUNCTION();
		// Do Initializtion stuff
		ErrorCode error;
		error = Log::initialize();

		if (error != ErrorCode::NoError) // TODO: make it a macro (for cleaner code)
			return error;

		return ErrorCode::NoError;
	}

	ErrorCode Application::Run()
	{
		// The Engine loop
		return ErrorCode::NoError;
	}
}
