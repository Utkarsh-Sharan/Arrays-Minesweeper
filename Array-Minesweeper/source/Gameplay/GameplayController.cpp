#include "Gameplay/GameplayController.h"
#include "Global/ServiceLocator.h"
#include "Gameplay/Board/BoardController.h"

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

	void GameplayController::render()
	{

	}

	void GameplayController::reset()
	{
		remaining_time = max_duration;
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}

	int GameplayController::getMinesCount()
	{
		return board_controller->getMinesCount();
	}
}