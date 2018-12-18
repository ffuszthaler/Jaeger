#pragma once

#ifdef JG_PLATFORM_WINDOWS

extern Jaeger::Application* Jaeger::CreateApplication();

int main(int argc, char** argv) {

	Jaeger::Log::Init();
	JG_CORE_WARN("Initialized Log!");
	int a = 5;
	JG_INFO("Hello! Var={0}", a);

	auto app = Jaeger::CreateApplication();
	app->Run();
	delete app;
}

#endif
