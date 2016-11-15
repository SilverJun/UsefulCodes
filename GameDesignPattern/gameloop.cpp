//
//MarioBadr`s GameLoop
//https://gist.github.com/mariobadr/673bbd5545242fcf9482
//
//this file is gameloop based MarioBadr`s gameloop
//

#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

//frame lock to 60fps
constexpr std::chrono::nanoseconds MS_PER_UPDATE(16ms);
using clock = std::chrono::high_resolution_clock;

class Game {
	std::chrono::nanoseconds _lag;
	std::chrono::time_point<std::chrono::steady_clock> _timeStart;
	bool _isQuit;

public:
	void init()
	{
		_lag = 0ns;
		_timeStart = clock::now();
		_isQuit = false;
	}
	void release()
	{

	}
	void update()
	{

	}
	void render()
	{

	}

	void gameLoop()
	{
		while (!_isQuit) {
			auto delta_time = clock::now() - _timeStart;
			_timeStart = clock::now();
			_lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

			while (_lag >= MS_PER_UPDATE) {
				update();
				_lag -= MS_PER_UPDATE;
			}

			render();
		}
	}
};

int main() {

	Game* game = new Game;

	game->init();
	game->gameLoop();
	game->release();
	
	return 0;
}