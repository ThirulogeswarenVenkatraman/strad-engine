#ifndef BALL_H
#define BALL_H

#include "strawberry/particle.h"
#include "strawberry/pfGenerator.h"

class Ball {
	Particle ball_props;
	GravityGenerator GravityGen;
public:
	Ball(strad gg);

	void UpdateBall(float delta);
	void RenderBall();
};


#endif