#pragma once

#include "Gameplay/Board/BoardController.h"

namespace Gameplay
{
	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	private:
		const float max_duration = 201.f;
		const float game_over_time = 11.f;
		float remaining_time;

		GameResult game_result;
		Board::BoardController* board_controller;

		void updateRemainingTime();

		void gameWon();
		void gameLost();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		float getRemainingTime();

		void beginGameOverTimer();
		void endGame(GameResult result);

		void reset();
	};
}