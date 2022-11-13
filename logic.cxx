#include "strawberry/game.h"
#include "strawberry/InputHandler.h"
#include "strawberry/TextureManager.h"
#include "strawberry/tilemap.h"

#include "king.h"

static King* king{ nullptr };
static TileMap* myMap{ nullptr };
void game::Start()
{
	king = { new King(0) };
	myMap = new TileMap("assets/arena.tmx");
}

void game::Update(float dt) 
{
	king->UpdateKing(dt);
}

void game::Render() 
{
	myMap->draw_map();
	king->RenderKing();
}

void game::FreeResrc()
{
	/* heap managers */
	delete myMap;
	delete king;
	delete ParticleForceRegistry::getInstance();
	delete TextureManager::getInstance();
}