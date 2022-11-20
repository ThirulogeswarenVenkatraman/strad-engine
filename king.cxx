#include "king.h"
#include "strawberry/vector2d.h"
#include "strawberry/InputHandler.h"
#include "strawberry/TextureManager.h"

#include "strawberry/game.h"

// row starts from 1 to ... and column from 0 to ...;
King::King(strad gg) : acceleration{ 0.0f,0.0f }, speed{ 190.0f }, king_anims{}
{
	flipval = SDL_FLIP_NONE;
	king_props.SetPosition(300.0f, 90.0f)->SetVelocity(0.0f, 0.0f)->SetAcceleration(0.0f, 0.0f);
	king_props.SetDamping(0.99f)->SetMass(400.0f);

	king_anims.load_state("assets/king/Idle.png", "kingIdle", { 11, 100.0f });
	king_anims.load_state("assets/king/Run.png", "kingRun", { 8, 100.0f });
}

King::~King() {
	fprintf(stdout, "Dead King\n");
}

void King::UpdateKing(float delta)
{
	acceleration.clear();
	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_W)) {
		acceleration.y -= speed; 
	}
	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_A)) {
		acceleration.x -= speed; flipval = SDL_FLIP_HORIZONTAL;
	}
	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_S)) {
		acceleration.y += speed; 
	}
	if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_D)) {
		acceleration.x += speed; flipval = SDL_FLIP_NONE;
	}
	if (InputHandler::getInstance()->isKeyUp(SDL_SCANCODE_W) &&
		InputHandler::getInstance()->isKeyUp(SDL_SCANCODE_A) &&
		InputHandler::getInstance()->isKeyUp(SDL_SCANCODE_S) &&
		InputHandler::getInstance()->isKeyUp(SDL_SCANCODE_D)) { // Idle
		king_anims.set_anim_state("kingIdle");
	}
	else {
		king_anims.set_anim_state("kingRun");
	}

	king_props.SetVelocity(acceleration.x, acceleration.y);
	king_props.Integrator(delta);
}
const SDL_Rect rs = { 32 * 2, 160 * 2, 128 * 2, 32 * 2 };
void King::RenderKing() // 858 by 58
{
	SDL_SetRenderDrawColor(game::getInstance()->getRenderer(), 255, 0, 0,255);
	SDL_RenderDrawRect(game::getInstance()->getRenderer(), &rs);
	king_anims.update_animation();
	TextureManager::getInstance()->DrawFrame(king_anims.get_state_id(), king_props.getX(),
		king_props.getY(), 78, 58, king_anims.getRow(), king_anims.getColumn(), flipval);
}