#include "animator.h"
#include "TextureManager.h"

Animator::Animator() : rFrame{ 1 }, cFrame{ 0 }, anim_pause { false } {
	_timer.start();
}

Animator::~Animator() {
	spritesheets.clear();
}

void Animator::loadState(std::string filename, std::string state_id, sheet_properties properties)
{
	TextureManager::getInstance()->Load(filename, state_id);
	spritesheets[state_id] = properties;
}

void Animator::setState(std::string state_id) {
	static bool once{ false };
	this->CurrentSheetID = state_id;
	this->in_totalframe = spritesheets[state_id].totalFrames;
	this->in_animationspeed = spritesheets[state_id].animation_speed;
	if(!once){
		_timer.stop();
		_timer.start();
		once = { true };
	}
}

void Animator::update_animation() {
	if (!anim_pause) {
		_timer.unpause();
	}
	else {
		_timer.pause();
	}
	this->CurrentColumnX = (((int)(_timer.getTicks() / this->in_animationspeed)) % this->in_totalframe);
}