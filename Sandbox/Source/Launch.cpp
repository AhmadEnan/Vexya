#include <Core/Application.h>
#include <Core/Entry.h>

class Sandbox : public Vexya::Application
{
public:
	Sandbox(/*const Vexya::ApplicationSpecification& specification*/)
		: Vexya::Application()
	{
		// PushLayer(new ExampleLayer());
		// PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Vexya::Application* Vexya::CreateApplication(/*Vexya::ApplicationCommandLineArgs args*/)
{
	// ApplicationSpecification spec;
	// spec.Name = "Sandbox";
	// spec.WorkingDirectory = "../Hazelnut";
	// spec.CommandLineArgs = args;

	return new Sandbox;
}