#include <Core/Application.h>

int main(int argc, char** argv) 
{
	Vexya::Application* app = new Vexya::Application();
	app->Init();
	return app->Run();
}