#ifndef _TEXTURE_MANAGER__H
#define _TEXTURE_MANAGER__H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <string>
#include <vector>
#include <map>

class TextureManager {
	TextureManager() = default;
	std::map<std::string, SDL_Texture*> qtextures;
	std::vector<std::string> tm_registry;

	void clean(std::string textureName);
public:
	~TextureManager();
	static TextureManager* getInstance();
	bool Load(std::string fileName, std::string id);

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip eFlip = SDL_RendererFlip::SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip eFlip = SDL_RendererFlip::SDL_FLIP_NONE);

	void DrawTile(std::string id, SDL_Rect* srcRect, SDL_Rect* dstRect);
};

#endif 
