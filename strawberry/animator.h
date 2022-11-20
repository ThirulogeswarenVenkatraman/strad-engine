#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "SDL2/SDL.h"
#include <string>
#include <map>

class Animator {
	bool anim_pause;
	int rFrame, cFrame;
	int internal_tframe;
	float animation_speed;
	std::string c_state_id;
	struct character_states {
		int totalFrames;
		float animation_speed;
	};
	std::map<std::string, character_states> c_state;
public:
	Animator();
	~Animator();

	int getRow();
	int getColumn();
	std::string get_state_id();

	void hold() { anim_pause = true; }
	void release() { anim_pause = false; }

	/* sprite-sheet for single state */
	void load_state(std::string filename, std::string state_id, character_states pstate);
	void set_anim_state(std::string state_id);
	/* full-sheet control */
	void set_framepos(int w_row, int w_column, float anim_speed = 100.0f);

	void update_animation();
};


#endif 
