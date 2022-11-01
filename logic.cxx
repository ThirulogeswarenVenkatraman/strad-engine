#include "strawberry/game.h"
#include "strawberry/InputHandler.h"
#include "strawberry/TextureManager.h"

#include "BallDemo.h"

static Ball* ballOne;

void game::Start()
{
	ballOne = { new Ball(19.07) };
}

void game::Update(float dt) 
{
	ballOne->UpdateBall(dt);
}

void game::Render() 
{
	ballOne->RenderBall();
}

void game::FreeResrc()
{
	/* heap managers */
	delete ballOne;
	delete ParticleForceRegistry::getInstance();
	delete TextureManager::getInstance();
}