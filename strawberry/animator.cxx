#include "animator.h"

static int internal_tframe;

Animator::Animator() : rFrame{ 1 }, cFrame{ 0 }, anim_pause { false } {
	Iactive = w_state::Idle;
}

Animator::~Animator() {
	c_state.clear();
}

std::string Animator::get_state_id() {
	return c_state.at((int)Iactive).state_id;
}

int Animator::getRow() { return this->rFrame; }
int Animator::getColumn() { return this->cFrame; }

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
	internal_tframe = c_state.at((int)Iactive).totalFrames;
	this->animation_speed = c_state.at((int)Iactive).animation_speed;
}

void Animator::set_framepos(int w_row, int w_column, float anim_speed) {
	this->rFrame = w_row;
	internal_tframe = w_column;
	this->animation_speed = anim_speed;
}

void Animator::update_animation() {
	if (!anim_pause) {
		cFrame = (((int)(SDL_GetTicks() / this->animation_speed)) % internal_tframe);
	}
}