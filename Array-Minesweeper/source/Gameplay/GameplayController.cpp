#include "Gameplay/GameplayController.h"
#include "Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Time;
	using namespace Board;

	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{
		updateRemainingTime();
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void GameplayController::beginGameOverTimer() 
	{ 
		remaining_time = game_over_time;
	}

	void GameplayController::endGame(GameResult result)
	{
		// The switch statement handles the different possible outcomes of the game.
		switch (result)
		{
		case GameResult::WON:
			gameWon();
			break;

		case GameResult::LOST:
			gameLost();
			break;
		}
	}

	void GameplayController::gameWon()
	{
		// Implement game won specific logic here.
	}

	void GameplayController::gameLost()
	{
		// Implement game lost specific logic here.
	}

	void GameplayController::render()
	{

	}

	void GameplayController::reset()
	{
		remaining_time = max_duration;
		game_result = GameResult::NONE;

		ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}
}