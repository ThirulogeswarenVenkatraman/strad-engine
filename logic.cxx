#include "strawberry/game.h"
#include "strawberry/InputHandler.h"
#include "strawberry/TextureManager.h"
#include "strawberry/tilemap.h"

#include "king.h"

static King* king{ nullptr };
static TileMap* mymap{ nullptr };
void game::Start()
{
	king = { new King(0) };
	mymap = { new TileMap("assets/level_one.tmx") };
}

void game::Update(float dt) 
{
	king->UpdateKing(dt);
}

void game::Render() 
{
	mymap->draw_map();
	king->RenderKing();
}

void game::FreeResrc()
{
	/* heap managers */
	delete mymap;
	delete king;
	delete ParticleForceRegistry::getInstance();
	delete TextureManager::getInstance();
}