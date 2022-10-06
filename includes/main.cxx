#include "game.h"
#include "Timer.h"

int main(int argc,char* argv[])
{ 
	if (game::getInstance()->Init("Mad Engine"))
	{
		fprintf(stdout, "RefreshRate: %d\n", game::getInstance()->getRefreshRate());
		fprintf(stdout, "sec_per_update = %f\n", (1.0f / (float)game::getInstance()->getRefreshRate()));
		const float FixedDeltaTime = 1.0f / (float)game::getInstance()->getRefreshRate();
		float previousTime = 0.0f;
		float lag = 0.0f;
		float max = 0.0f;
		while (game::getInstance()->isRunnning())
		{
			float DeltaTime = InSec() - previousTime;
			previousTime = InSec();
			lag += DeltaTime;
			game::getInstance()->HandleEvents();

			while (lag >= FixedDeltaTime)
			{
				game::getInstance()->HandleEvents();
				game::getInstance()->Update(FixedDeltaTime);
				lag -= FixedDeltaTime;
			}
			game::getInstance()->Render();
		}
	}
	else { fprintf(stderr, "Game Init() failed!\n"); return -1; }
	game::getInstance()->clean();
	fprintf(stdout, "Subsystem Cleaned UP !\n");
	return 0;
}
