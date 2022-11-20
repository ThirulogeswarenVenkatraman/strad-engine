#include "TextureManager.h"

#include "game.h" /* renderer */

constexpr float c_size{ 2.2 };

TextureManager* TextureManager::getInstance()
{   
    static TextureManager* textinst{ new TextureManager() };
    return textinst;
}
TextureManager::~TextureManager() {
    for (auto textures : tm_registry) {
        this->clean(textures);
    }
    tm_registry.clear();
    fprintf(stdout, "Destroyed TextureManager\n");
}

bool TextureManager::Load(std::string fileName, std::string id)
{
    static SDL_Texture* tempTexture;
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    if (!tempSurface) {
        fprintf(stderr, "Load Error: %s\n", IMG_GetError());
        return false;
    }
    tempTexture = SDL_CreateTextureFromSurface(game::getInstance()->getRenderer(), tempSurface);
    if (!tempTexture) {
        fprintf(stderr, "Load Error: %s\n", IMG_GetError());
        return false;
    }
    tm_registry.push_back(id);
    qtextures[id] = tempTexture;
    /* don't free the Texture */
    SDL_FreeSurface(tempSurface);
    tempSurface = NULL;
    tempTexture = NULL;
    return true;
}

void TextureManager::clean(std::string textureName)
{
    if (qtextures[textureName] != NULL) {
        SDL_Log("Freed %s", textureName.c_str());
        SDL_DestroyTexture(qtextures[textureName]);
    }
    qtextures[textureName] = NULL;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip eFlip)
{
    static SDL_Rect SrcRect;
    static SDL_Rect DestRect;

    SrcRect.x = 0;
    SrcRect.y = 0;
    DestRect.x = x;
    DestRect.y = y;

    SrcRect.w = width; DestRect.w = width * c_size;
    SrcRect.h = height; DestRect.h = height * c_size;

    SDL_RenderCopyEx(game::getInstance()->getRenderer(), qtextures[id], &SrcRect, &DestRect, 0, 0, eFlip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip eFlip)
{
    static SDL_Rect SrcRect;
    static SDL_Rect DestRect;

    SrcRect.x = width * currentFrame;
    SrcRect.y = height * (currentRow - 1);
    DestRect.x = x;
    DestRect.y = y;

    SrcRect.w = width; DestRect.w = width * c_size;
    SrcRect.h = height; DestRect.h = height * c_size;

    SDL_RenderCopyEx(game::getInstance()->getRenderer(), qtextures[id], &SrcRect, &DestRect, 0, 0, eFlip);
}

void TextureManager::DrawTile(std::string id, SDL_Rect* srcRect, SDL_Rect* dstRect)
{
    SDL_RenderCopy(game::getInstance()->getRenderer(), qtextures[id], srcRect, dstRect);
}
