#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "SDL2/SDL.h"
#include <string>
#include <vector>

enum class w_state { Idle, Run, Attack };

class Animator {
	int rFrame, cFrame;
	bool anim_pause;
	float animation_speed;
	w_state Iactive;
	struct character_states {
		std::string state_id;
		float animation_speed;
		int totalFrames;
	};
	std::vector<character_states> c_state;
public:
	Animator();
	~Animator();

	std::string get_state_id();
	int getRow();
	int getColumn();

	void hold() { anim_pause = true; }
	void release() { anim_pause = false; }

	/* sprite-sheet for single state */
	void add_state(std::string state, int tFrames, float anim_speed);
	void set_anim_state(w_state active_state);
	/* full-sheet control */
	void set_framepos(int w_row, int w_column, float anim_speed = 100.0f);

	void update_animation();
};


#endif 
