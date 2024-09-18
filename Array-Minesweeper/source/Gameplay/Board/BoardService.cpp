#include "Gameplay/Board/BoardService.h"
#include "Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace UI::UIElement;

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

		void BoardService::processCellInput(Cell::CellController* cell_controller, ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
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