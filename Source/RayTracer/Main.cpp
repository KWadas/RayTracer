#include <iostream>
#include "Renderer.h"
#include "Canvas.h"
#include "Ray.h"
#include "Random.h"
#include "Camera.h"
#include "Scene.h"
#include "Material.h"
#include "Object.h"
#include "Sphere.h"
#include <memory>

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

	float aspectRatio = canvas.GetSize().x / (float)canvas.GetSize().y;
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 0, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 70.0f, aspectRatio);

	Scene scene; // sky color could be set with the top and bottom color
	scene.SetCamera(camera);

	// create material
	auto material = std::make_shared<Lambertian>(color3_t{ 0, 0, 1 });

	// create objects -> add to scene
	for (int i = 0; i < 6; i++)
	{
		auto sphere = std::make_unique<Sphere>(glm::vec3{ random(-6, 6),random(-5, 5), random(-6, -18) }, random(1, 5), material);
		scene.AddObject(std::move(sphere));
	}
	

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
		scene.Render(canvas);
		canvas.Update();

		renderer.PresentCanvas(canvas);
	}

	return 0;
}