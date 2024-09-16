#include "Gameplay/Board/BoardController.h"
#include "Gameplay/Board/BoardView.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;

		BoardController::BoardController()
		{
			board_view = new BoardView(this);
		}

		BoardController::~BoardController()
		{

		}

		void BoardController::createBoard()
		{

		}

		void BoardController::initialize()
		{
			board_view->initialize();
		}

		void BoardController::update()
		{
			board_view->update();
		}

		void BoardController::render()
		{
			board_view->render();
		}

		void BoardController::destroy()
		{
			board_view = nullptr;

			delete(board_view);
		}

		void BoardController::deleteBoard()
		{

		}

		void BoardController::reset()
		{

		}
	}
}