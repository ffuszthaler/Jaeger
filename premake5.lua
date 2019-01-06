workspace "Jaeger"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Jaeger/vendor/GLFW/include"

include "Jaeger/vendor/GLFW"

project "Jaeger"
	location "Jaeger"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "jgpch.h"
  pchsource "Jaeger/src/jgpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
    "%{IncludeDir.GLFW}"
	}

  links {
    "GLFW",
    "opengl32.lib"
  }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"JG_PLATFORM_WINDOWS",
			"JG_BUILD_DLL"
		}
	
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "JG_DEBUG"
    buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "JG_RELEASE"
    buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "JG_DIST"
    buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Jaeger/vendor/spdlog/include",
		"Jaeger/src"
	}

	links {
		"Jaeger"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"JG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "JG_DEBUG"
    buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "JG_RELEASE"
    buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "JG_DIST"
    buildoptions "/MD"
		optimize "On"