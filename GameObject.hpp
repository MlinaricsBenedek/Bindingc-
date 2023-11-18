#pragma once
#include "GameEngine.hpp"
class Gameobject
{
public:
	Gameobject(const char* sheet,int x, int y);
	~Gameobject();
	void Update();
	void Render();
private:
	int xpos;
	int ypos;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
	
};