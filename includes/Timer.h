#ifndef SE_TIMER_H
#define SE_TIMER_H

#include "SDL2/SDL.h"

inline float InSec()
{
	float time = SDL_GetTicks();
	time /= 1000.0f;
	return time; //in seconds
}

#endif 
