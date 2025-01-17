#pragma once

#include "Gameplay/GameplayController.h"

namespace Gameplay
{
	class GameplayController;

	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void startGame();

		float getRemainingTime();
		int getMinesCount();

		void endGame(GameResult result);
	};
}