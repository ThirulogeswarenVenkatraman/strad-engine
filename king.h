#ifndef _KING_H
#define _KING_H

#include "strawberry/particle.h"
#include "strawberry/pfGenerator.h"

#include "strawberry/Animator.h"

class King {
	Animator king_anims;
	Particle king_props;
	SDL_RendererFlip flipval;
private:
	Vector2 acceleration;
	strad speed;
public:
	King(strad gg);
	~King();

	void UpdateKing(float delta);
	void RenderKing();
};

#endif