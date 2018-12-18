#pragma once

#ifdef JG_PLATFORM_WINDOWS

extern Jaeger::Application* Jaeger::CreateApplication();

int main(int argc, char** argv) {
	auto app = Jaeger::CreateApplication();
	app->Run();
	delete app;
}

#endif
