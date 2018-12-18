#pragma once

#include "Core.h";

namespace Jaeger {
	class JAEGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	// To be defined in Client
	Application* CreateApplication();
}

