#include "strawberry/game.h"
#include "strawberry/InputHandler.h"
#include "strawberry/TextureManager.h"

void game::Start()
{

}

void game::Update(float dt) 
{

}

void game::Render() 
{

}

void game::FreeResrc()
{
	/* heap managers */
	delete TextureManager::getInstance();
}