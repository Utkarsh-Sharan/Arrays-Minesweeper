#pragma once

#include "Gameplay/Board/BoardService.h"
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
		const float max_duration = 101.f;
		const float game_over_time = 11.f;
		float remaining_time;

		GameResult game_result;
		Board::BoardService* board_service;

		void updateRemainingTime();

		void gameWon();
		void gameLost();
		void beginGameOverTimer();
		bool isTimeOver();
		void showCredits();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		float getRemainingTime();

		void endGame(GameResult result);

		void reset();
	};
}