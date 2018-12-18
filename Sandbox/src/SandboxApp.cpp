#include <Jaeger.h>

class Sandbox : public Jaeger::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Jaeger::Application* Jaeger::CreateApplication() {
	return new Sandbox();
}