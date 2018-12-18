#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Jaeger {

	class JAEGER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define JG_CORE_FATAL(...)      ::Jaeger::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define JG_CORE_ERROR(...)      ::Jaeger::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JG_CORE_WARN(...)       ::Jaeger::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JG_CORE_INFO(...)       ::Jaeger::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JG_CORE_TRACE(...)      ::Jaeger::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define JG_FATAL(...)           ::Jaeger::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define JG_ERROR(...)           ::Jaeger::Log::GetClientLogger()->error(__VA_ARGS__)
#define JG_WARN(...)            ::Jaeger::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JG_INFO(...)            ::Jaeger::Log::GetClientLogger()->info(__VA_ARGS__)
#define JG_TRACE(...)           ::Jaeger::Log::GetClientLogger()->trace(__VA_ARGS__)

