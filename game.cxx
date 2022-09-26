#include "include/game.h"
#include "include/InputHandler.h"

#define WINDOW_POS_X 1280
#define WINDOW_POS_Y 720

game* game::gameinst = nullptr;

game* game::getInstance()
{
	if (gameinst == nullptr)
	{
		gameinst = new game();
		return gameinst;
	}
	return gameinst;
}

SDL_Renderer* game::getRenderer()
{
	return this->renderer;
}

bool game::isRunnning()
{
	return this->state;
}

void game::setState(bool state)
{
	this->state = state;
}

int game::getRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}

bool game::Init(const char* title)
{
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "%s", SDL_GetError());
		return false;
	}
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, 
	SDL_WINDOWPOS_CENTERED, WINDOW_POS_X, WINDOW_POS_Y, 0);
	
	if (!window) {
		fprintf(stderr, "%s", SDL_GetError());
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer) {
		fprintf(stderr, "%s", SDL_GetError());
		return false;
	}

	
	/* if everything went ok */
	this->state = true;
	return true;
}

void game::HandleEvents()
{
	InputHandler::getInstance()->EventUpdater();
}

void game::Update(float dt)
{

}

void game::Render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void game::clean()
{
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	if (window != NULL) {
		SDL_DestroyWindow(window);
		window = NULL;
	}
	SDL_Quit();
}