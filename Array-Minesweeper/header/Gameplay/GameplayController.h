#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:
		const float max_duration = 60.f;
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