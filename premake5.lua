workspace "Vexya"
	architecture "x86_64"
	startproject "Sandbox"

	-- configurations
	configurations {
		"Debug",    -- Debug
		"Release",  -- Release
		"Dist"      -- Distribute
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
		"Vexya/src/**.cpp"
	}
	
	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"VEXYA_ENGINE"
	}

	includedirs {
		"Vexya/Include",
		-- "%{Deps.fmt}",
		-- "%{Deps.glm}",
		"Thirdparty"
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

	filter "configurations:Dist"
		defines "VX_DIST"
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
		"Vexya-Editor/Include/**.h",
		"Vexya-Editor/Source/**.cpp"
	}
	
	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"VEXYA_ENGINE"
	}
	
	includedirs {
		"Vexya-Editor/Include",
		-- "%{Deps.glm}",
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
	
	filter "configurations:Dist"
		defines "VX_DIST"
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
		"Sandbox/Include/**.h",
		"Sandbox/Source/**.cpp"
	}
	
	includedirs {
		"Sandbox/Include",
		"%{Deps.glm}",
		"Thirdparty"
	}
	
	links {
		"Vexya" -- ,
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
	
	filter "configurations:Dist"
		defines "VX_DIST"
		runtime "Release"
		optimize "on"