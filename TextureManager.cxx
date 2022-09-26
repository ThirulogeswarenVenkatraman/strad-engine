#include "include/TextureManager.h"

TextureManager* TextureManager::textinst = 0;

TextureManager* TextureManager::getInstance()
{
    if (textinst == 0)
    {
        textinst = new TextureManager();
        return textinst;
    }
    return textinst;
}

bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    /*if (tempSurface != 0)
    {
        Texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }
    else { std::cerr << "TEMP Surface Creation Failed!\n" << SDL_GetError(); return false; }
    if (Texture != 0)
    {
        qtextures[id] = Texture;
        return true;
    }
    else { std::cerr << "Texture Creation Failed!\n" << SDL_GetError(); return false; }
    */
    return false;
}

void TextureManager::clean(std::string textureName)
{
    SDL_DestroyTexture(qtextures[textureName]);
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect SrcRect;
    SDL_Rect DestRect;

    SrcRect.x = 0;
    SrcRect.y = 0;
    DestRect.x = x;
    DestRect.y= y;

    SrcRect.w = DestRect.w = width;
    SrcRect.h = DestRect.h = height;

    SDL_RenderCopyEx(renderer, qtextures[id], &SrcRect, &DestRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, 
    int currentFrame, SDL_Renderer* renderer, int FlipValue)
{
    SDL_Rect SrcRect;
    SDL_Rect DestRect;

    SrcRect.x = width * currentFrame;
    SrcRect.y = height * (currentRow - 1);
    DestRect.x = x;
    DestRect.y = y;

    SrcRect.w = DestRect.w = width;
    SrcRect.h = DestRect.h = height;
    if (FlipValue == 1)
    {
        SDL_RenderCopyEx(renderer, qtextures[id], &SrcRect, &DestRect, 0, 0,SDL_FLIP_HORIZONTAL);
    }
    else if(FlipValue==2)
    { 
        SDL_RenderCopyEx(renderer, qtextures[id], &SrcRect, &DestRect, 0, 0, SDL_FLIP_VERTICAL);
    }
    else
    {
        SDL_RenderCopyEx(renderer, qtextures[id], &SrcRect, &DestRect, 0, 0,SDL_FLIP_NONE);
    }
    
}
