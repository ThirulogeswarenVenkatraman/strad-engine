#ifndef _TIMER__H
#define _TIMER__H

inline float InSec()
{
	float time = SDL_GetTicks();
	time /= 1000.0f;
	return time; //in seconds
}

#endif 
