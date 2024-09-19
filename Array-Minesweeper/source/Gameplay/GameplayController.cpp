#include "Gameplay/GameplayController.h"
#include "Global/ServiceLocator.h"
#include "Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Time;
	using namespace Board;
	using namespace Main;

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

		if (isTimeOver())
		{
			if(game_result == GameResult::LOST)
				endGame(GameResult::LOST);
			else if(game_result == GameResult::WON)
				endGame(GameResult::WON);
		}
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
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
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::WON;
			beginGameOverTimer();
			ServiceLocator::getInstance()->getBoardService()->flagAllMines();
			ServiceLocator::getInstance()->getBoardService()->setBoardState(BoardState::COMPLETED);
			//ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::GAME_WON);
		}
		else
		{
			showCredits();
		}
	}

	void GameplayController::gameLost()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;
			beginGameOverTimer();
			ServiceLocator::getInstance()->getBoardService()->showBoard();
			ServiceLocator::getInstance()->getBoardService()->setBoardState(BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}
	}

	void GameplayController::beginGameOverTimer()
	{
		remaining_time = game_over_time;
	}

	bool GameplayController::isTimeOver() 
	{ 
		return (remaining_time <= 1);
	}

	void GameplayController::showCredits() 
	{ 
		GameService::setGameState(GameState::CREDITS);
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