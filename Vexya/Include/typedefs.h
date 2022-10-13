#pragma once
#include <inttypes.h>

namespace Vexya 
{
	typedef void* Pointer;
	typedef unsigned long long size_t;

	// Int Types
	typedef signed char        Int8;
	typedef short              Int16;
	typedef int                Int32;
	typedef long long          Int64;

	// Unsigned int Types
	typedef unsigned char      Uint8;
	typedef unsigned short     Uint16;
	typedef unsigned int       Uint32;
	typedef unsigned long long Uint64;

	typedef unsigned long long Uintptr;

	typedef Uint32 RendererID;
}