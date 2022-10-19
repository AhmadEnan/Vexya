#pragma once

#include "Base.h"
#include "Core/Application.h"

#ifdef VX_WINDOWS

extern Vexya::Application* Vexya::CreateApplication(/*ApplicationCommandLineArgs args*/);

int main(int argc, char** argv)
{
	// Vexya::Log::Init();

	VX_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = Vexya::CreateApplication(/*{argc, argv}*/);
	VX_PROFILE_END_SESSION();

	VX_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	VX_PROFILE_END_SESSION();

	VX_PROFILE_BEGIN_SESSION("Shutdown", "HazelProfile-Shutdown.json");
	delete app;
	VX_PROFILE_END_SESSION();
}

#endif