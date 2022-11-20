#include "animator.h"
#include "TextureManager.h"

Animator::Animator() : rFrame{ 1 }, cFrame{ 0 }, anim_pause { false } {
	
}

Animator::~Animator() {
	c_state.clear();
}

int Animator::getRow() { return this->rFrame; }
int Animator::getColumn() { return this->cFrame; }
std::string Animator::get_state_id() { return this->c_state_id; }

void Animator::load_state(std::string filename, std::string state_id, character_states pstate)
{
	TextureManager::getInstance()->Load(filename, state_id);
	
	c_state[state_id] = pstate;
}

void Animator::set_anim_state(std::string state_id) {
	this->c_state_id = state_id;

	this->internal_tframe = c_state[state_id].totalFrames;
	this->animation_speed = c_state[state_id].animation_speed;
}

void Animator::set_framepos(int w_row, int w_column, float anim_speed) {
	this->rFrame = w_row;
	this->internal_tframe = w_column;
	this->animation_speed = anim_speed;
}

void Animator::update_animation() {
	if (!anim_pause) {
		cFrame = (((int)(SDL_GetTicks() / this->animation_speed)) % internal_tframe);
	}
}