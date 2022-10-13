#include <Core/Application.h>

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
		// Do Initializtion stuff
		return ErrorCode::NoError;
	}

	ErrorCode Application::Run()
	{
		// The Engine loop
		return ErrorCode::NoError;
	}
}
