#include "GameEngine.hpp"
#include "strukm.hpp"
#include "GameObject.hpp"
Gameobject* player;
Gameobject* enemy;
SDL_Renderer* GEngine::renderer = nullptr;
GEngine::GEngine()
{
}
GEngine::~GEngine()
{
}
void GEngine:: initialize(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Az inicializáció sikeres volt" << endl;


		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "Létrehoztuk az ablakot!" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) 
		{	
			SDL_SetRenderDrawColor(renderer, 34, 34, 255, 255);
			cout << "Renderer" << endl;
		}
		running = true;
	}
	else
	{
		cout << "Az ablak létrehozása sikertelen volt" << endl;
		running = false;
	}
	player = new Gameobject("asset/karakter.png",0,0);
	enemy = new Gameobject("asset/enemy2.png", 100, 100);
}


void GEngine::handleEv()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
	running = false;
	default:
		break;
	}
}
void GEngine::update()
{

	player->Update();
	enemy->Update();
}

void GEngine::render()
{
	
	SDL_RenderClear(renderer);
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);

}

void GEngine::clean()
{ //clean games
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}
