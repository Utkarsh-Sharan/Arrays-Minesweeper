#include "Gameplay/Board/BoardService.h"
#include "Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{
		BoardService::BoardService()
		{
			board_controller = nullptr;
		}

		BoardService::~BoardService()
		{
			destroy();
		}

		void BoardService::initialize()
		{
			board_controller = new BoardController();

			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		void BoardService::destroy()
		{
			board_controller = nullptr;

			delete(board_controller);
		}
	}
}