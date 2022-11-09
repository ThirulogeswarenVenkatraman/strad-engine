#include "animator.h"

Animator::Animator() : rFrame{ 1 }, cFrame{ 0 }, anim_pause { false } {
	Iactive = w_state::Idle;
}

Animator::~Animator() {
	c_state.clear();
}

void Animator::add_state(std::string state, int tFrames, float anim_speed)
{
	character_states temp_c_state;
	temp_c_state.state_id = state;
	temp_c_state.animation_speed = anim_speed;
	temp_c_state.totalFrames = tFrames;

	c_state.push_back(temp_c_state);
}

void Animator::set_anim_state(w_state active_state) {
	Iactive = { active_state };
	this->tFrame = c_state.at((int)Iactive).totalFrames;
	this->animation_speed = c_state.at((int)Iactive).animation_speed;
}

void Animator::set_FramePos(int w_row, int w_column, float anim_speed) {
	this->rFrame = w_row;
	this->tFrame = w_column;
	this->animation_speed = anim_speed;
}

void Animator::update_animation() {
	if (!anim_pause) {
		cFrame = (((int)(SDL_GetTicks() / this->animation_speed)) % tFrame);
	}
}