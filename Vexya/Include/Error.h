#pragma once

namespace Vexya 
{
	enum ErrorCode
	{
		NoError = 0xf0, // No errors (thanks god)
		WindowCreationFail = 0xf1, // Failed to create the 'Main Window'
		LoggingInitializationFail = 0xf2, // Failed to initialize the logging system
	};
}