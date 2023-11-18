#include "GameEngine.hpp"
GEngine* eng = nullptr;


int main(int arcj, char* kr[])
{
	const int FPS = 60;
	const int gametimeDELAY = 1000 / FPS;


	Uint32 gamestart;
	int gametime;

	eng = new GEngine;
	eng->initialize("title",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,1000,800,false);
	while (eng->GameIsRunning())
	{
		
		gamestart = SDL_GetTicks();
		eng->handleEv();
		eng->update();
		eng->render();
		gametime = SDL_GetTicks() - gamestart;
		if (gametimeDELAY > gametime)
		{
			SDL_Delay(gametimeDELAY-gametime);
		}
	}
	eng->clean();
	return 0;
}