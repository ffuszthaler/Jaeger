#include <Jaeger.h>

class ExampleLayer : public Jaeger::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		JG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Jaeger::Event& event) override {
		JG_TRACE("{0}", event);
	}
};

class Sandbox : public Jaeger::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Jaeger::Application* Jaeger::CreateApplication() {
	return new Sandbox();
}