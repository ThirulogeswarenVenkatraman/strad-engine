#include "BallDemo.h"
#include "strawberry/TextureManager.h"

Ball::Ball(strad gg) : GravityGen{ gg } {

	ball_props.SetPosition(300.0f, 90.0f);
	ball_props.SetVelocity(0.0f, 0.0f);
	ball_props.SetAcceleration(0.0f, 0.0f);
	
	ball_props.SetDamping(0.99f);
	ball_props.SetMass(7066.0f);
	
	ParticleForceRegistry::getInstance()->add(&ball_props, &GravityGen);
	TextureManager::getInstance()->Load("assets/BombOff.png", "Bomb");
	fprintf(stdout, "%f\n", ball_props.getMass());
}

Ball::~Ball() {
	fprintf(stdout, "Bomb bomed");
}

void Ball::UpdateBall(float delta) {
	ball_props.Integrator(delta);
}
void Ball::RenderBall() {
	TextureManager::getInstance()->Draw("Bomb", ball_props.getX(), ball_props.getY(), 13, 16);
}