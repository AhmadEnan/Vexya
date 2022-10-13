#pragma once
#include <typedefs.h>

// Application Mode (defined at Compilation)
#if defined VX_DEBUG
	#define VX_APP_MODE 0
#elif defined VX_RELEASE
	#define VX_APP_MODE 1
#elif defined VX_SHIPPING
	#define VX_APP_MODE 2
#endif