#include "GameObject.hpp"
#include "strukm.hpp"
Gameobject::Gameobject(const char* sheet,int x,int y)
{
	
	objectTexture = Strukman::LoadTexture(sheet);
	xpos = x;
	ypos = y;
}
void Gameobject::Update() 
{
	
	xpos++;
	ypos++;
	srcRect.h = 1500;
	srcRect.w = 1024;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = 100;
	destRect.w = 80;
}
void Gameobject::Render()
{
	SDL_RenderCopy(GEngine::renderer,objectTexture, &srcRect, &destRect);
}