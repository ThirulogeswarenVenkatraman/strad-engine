#ifndef _GAME__H
#define _GAME__H

#include "SDL2/SDL.h"
#include <memory>

class game
{
	bool state;
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunnning();
	int getRefreshRate();

	game(const int win_pos_x, const int win_pos_y);
	~game();
	
	void Start();
	void Update(float dt);
	void Render();
	void FreeResrc();

public:

	SDL_Renderer* getRenderer();
	static game* getInstance();
	
	void setState(bool state);
	void RunTheGame();
};

#endif // !SE_GAME_H
