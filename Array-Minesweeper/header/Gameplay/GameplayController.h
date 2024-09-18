#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:
		const float max_duration;
		float remaining_time;

		void updateRemainingTime();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		float getRemainingTime();

		void reset();
	};
}