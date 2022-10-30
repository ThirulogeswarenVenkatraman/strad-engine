#include "BallDemo.h"
#include "strawberry/TextureManager.h"

Ball::Ball(strad gg) : GravityGen{ gg } {

	ball_props.SetPosition(300.0f, 300.0f);
	ball_props.SetVelocity(0.0f, 0.0f);
	ball_props.SetAcceleration(0.0f, 0.0f);
	
	ball_props.SetDamping(0.99f);
	ball_props.SetMass(60.0f);

	TextureManager::getInstance()->Load("assets/ball.png", "Ball");
}

void Ball::UpdateBall(float delta) {
	GravityGen.UpdateForce(&ball_props, delta);
	ball_props.Integrator(delta);
}
void Ball::RenderBall() {
	TextureManager::getInstance()->DrawFrame("Ball", 0, 0, 86, 90, 1, 1);
}