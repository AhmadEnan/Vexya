#pragma once
#include <inttypes.h>
#include <memory>

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

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}