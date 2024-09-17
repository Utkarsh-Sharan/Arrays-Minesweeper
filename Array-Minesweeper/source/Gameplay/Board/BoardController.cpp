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
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b] = new CellController(sf::Vector2i(a, b));
				}
			}
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b]->initialize(cell_width, cell_height);
				}
			}
		}

		void BoardController::update()
		{
			board_view->update();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b]->render();
				}
			}
		}

		void BoardController::destroy()
		{
			deleteBoard();

			board_view = nullptr;

			delete(board_view);
		}

		void BoardController::deleteBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b] = nullptr;

					delete(board[a][b]);
				}
			}
		}

		void BoardController::reset()
		{
			resetBoard();
		}

		void BoardController::resetBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b]->reset();
				}
			}
		}
	}
}