#pragma once

namespace Gameplay
{
	class BoardController;

	class GameplayController
	{
	private:
		const float max_duration = 60.f;
		float remaining_time;

		Board::BoardController* board_controller;

		void updateRemainingTime();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		float getRemainingTime();
		int getMinesCount();

		void reset();
	};
}