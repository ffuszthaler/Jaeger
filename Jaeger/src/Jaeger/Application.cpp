#include "jgpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Jaeger {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication)) {
			JG_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {
			JG_TRACE(e);
		}

		while (true);
	}

}
