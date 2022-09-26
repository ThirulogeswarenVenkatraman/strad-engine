#ifndef SE_TEXTURE_MANAGER_H
#define SE_TEXTURE_MANAGER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "string"
#include "map"

class TextureManager {
	static TextureManager* textinst;
	std::map<std::string, SDL_Texture*> qtextures;
	SDL_Texture* Texture;
public:
	static TextureManager* getInstance();
	bool Load(std::string fileName, std::string id, SDL_Renderer* renderer);

	void clean(std::string textureName);

	void Draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow,
		int currentFrame, SDL_Renderer* renderer, int FlipValue);
};

#endif 
