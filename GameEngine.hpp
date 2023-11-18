#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
using namespace std;

class GEngine
{
public:
	GEngine();
	~GEngine();
	void initialize(const char *title,int xpos,int ypos, int width, int height, bool fullscreen);
	void render() ;
	void handleEv();
	void update();
	void clean();
	bool GameIsRunning() { return running; }
	static SDL_Renderer* renderer;
private:
	bool running;
	int cnt = 0;
	SDL_Window* window;

	
};


 