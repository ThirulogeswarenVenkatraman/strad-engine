#ifndef SE_INPUT_HANDLER_H
#define SE_INPUT_HANDLER_H

#include "SDL2/SDL.h"
#include "vector"

enum mouseButtons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
	const Uint8* keyStates;
	std::vector<bool> mouseStates;
	static InputHandler* InputHanderInst;

	void MouseButtonDown(SDL_Event& q_event);
	void MouseButtonUp(SDL_Event& q_event);

public:
	InputHandler();
	static InputHandler* getInstance();
	void EventUpdater();

	bool getMouseButtonState(int button);
	bool isKeyDown(SDL_Scancode key);
};

#endif // !SE_INPUTHANDLER_H
