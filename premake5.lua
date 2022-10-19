workspace "Vexya"
	architecture "x86_64"
	startproject "Sandbox"

	-- configurations
	configurations {
		"Debug",    -- Debug Configuration (Less Optimized)
		"Release",  -- Release Configuration (Optimized, Recommedned for Beta testing)
		"Shipping"  -- Shipping Configuration (Fully Optimized)
	}

	flags { "MultiProcessorCompile" } -- Flags Applied to all Projects

-- Common output directory
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
--	include "Thirdparty/fmt"
group ""

Deps = {}
-- Deps["fmt"] = "Thirdparty/fmt/include"
-- Deps["glm"] = "Thirdparty/glm"


-- Vexya
-- The Engine
project "Vexya"
	location "Vexya"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"Vexya/Include/**.h",
		"Vexya/Source/**.cpp"
	}
	
	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"VEXYA_ENGINE"
	}

	includedirs {
		"Vexya/Include",
		-- "%{Deps.fmt}",
		-- "%{Deps.glm}",
		"Thirdparty",
		"Thirdparty/spdlog/include"
	}

	links {
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		defines "VX_WINDOWS"

	filter "system:linux"
		defines "VX_LINUX"

	filter "configurations:Debug"
		defines "VX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Shipping"
		defines "VX_SHIPPING"
		runtime "Release"
		optimize "on"

-- Vexya-Editor
-- A Fully Functional Level Editor
project "Vexya-Editor"
	location "Vexya-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"Vexya-Editor/**.h",
		"Vexya-Editor/**.cpp"
	}
	
	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"VEXYA_ENGINE"
	}
	
	includedirs {
		"Vexya-Editor/Include",
		-- "%{Deps.glm}",
		"Thirdparty/spdlog/include",
		"Vexya/Include"
	}
	
	links {
		"Vexya"-- ,
		-- "fmt"
	}
	
	filter "system:windows"
		systemversion "latest"
		defines "VX_WINDOWS"
	
	filter "system:linux"
		defines "VX_LINUX"
	
	filter "configurations:Debug"
		defines "VX_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "VX_RELEASE"
		runtime "Release"
		optimize "on"
	
	filter "configurations:Shipping"
		defines "VX_SHIPPING"
		runtime "Release"
		optimize "on"

-- Sandbox
-- The Testing Environment for the Engine
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"Sandbox/**.h",
		"Sandbox/**.cpp"
	}
	
	includedirs {
		"Sandbox/Include",
		"Vexya/Include",
		"%{Deps.glm}",
		"Thirdparty/spdlog/include",
		"Thirdparty"
	}
	
	links {
		"Vexya" 
		-- ,
		-- "fmt"
	}
	
	filter "system:windows"
		systemversion "latest"
		defines "VX_WINDOWS"

	filter "system:linux"
		defines "VX_LINUX"
			
	filter "configurations:Debug"
		defines "VX_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "VX_RELEASE"
		runtime "Release"
		optimize "on"
	
	filter "configurations:Shipping"
		defines "VX_SHIPPING"
		runtime "Release"
		optimize "on"