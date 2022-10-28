#include "includes/game.h"
#include "includes/InputHandler.h"
#include "includes/TextureManager.h"

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