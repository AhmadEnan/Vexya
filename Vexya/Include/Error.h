#pragma once

namespace Vexya 
{
	enum ErrorCode
	{
		NoError = 0xf0, // No errors (thanks god)
		WindowCreationFail = 0xf1, // Failed to create the 'Main Window' for some reason
	};
}