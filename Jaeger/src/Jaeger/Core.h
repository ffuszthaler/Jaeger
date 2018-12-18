#pragma once

#ifdef JG_PLATFORM_WINDOWS
	#ifdef JG_BUILD_DLL
		#define JAEGER_API __declspec(dllexport)
	#else
		#define JAEGER_API __declspec(dllimport)
	#endif
#else
	#error Jaeger only supports Window!
#endif
