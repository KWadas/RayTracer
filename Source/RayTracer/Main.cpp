#include <iostream>
#include "Renderer.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello World!\n";

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray-Tracing", 400, 300);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
	}

	return 0;
}