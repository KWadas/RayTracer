#include <iostream>
#include "Renderer.h"
#include "Canvas.h"
#include "Ray.h"
#include "Random.h"

int main(int, char**)
{
	static int width = 400;
	static int height = 300;
	
	std::cout << "Hello World!\n";
	seedRandom((unsigned int) time(nullptr));

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray-Tracing", width, height);
	Canvas canvas(width, height, renderer);



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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++) canvas.DrawPoint({ random(0, width), random(0, height)}, {random01(), random01(), random01(), 1});
		canvas.Update();

		renderer.PresentCanvas(canvas);
	}

	return 0;
}