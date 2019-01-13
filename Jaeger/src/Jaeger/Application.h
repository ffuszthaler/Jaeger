#pragma once

#include "Core.h"

#include "Window.h"
#include "Jaeger/LayerStack.h"
#include "Jaeger/Events/Event.h"
#include "Jaeger/Events/ApplicationEvent.h"

namespace Jaeger {

	class JAEGER_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }

		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};
	
	// To be defined in Client
	Application* CreateApplication();
}

