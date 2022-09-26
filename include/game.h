#ifndef SE_GAME_H
#define SE_GAME_H

#include "iostream"
#include "SDL2/SDL.h"

class game
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	static game* gameinst;
	bool state;
	
public:
	SDL_Renderer* getRenderer();
	
	static game* getInstance();
	bool isRunnning();
	void setState(bool state);

	int getRefreshRate();
	bool Init(const char* title);
	void HandleEvents();
	void Update(float dt);
	void Render();
	void clean();
};

#endif // !SE_GAME_H
