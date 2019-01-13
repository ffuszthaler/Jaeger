#pragma once

#include "Jaeger/Layer.h"

namespace Jaeger {

	class JAEGER_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();
		
		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;
	};
}
