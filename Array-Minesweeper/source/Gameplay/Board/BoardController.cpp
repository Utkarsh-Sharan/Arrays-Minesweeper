#include "Gameplay/Board/BoardController.h"
#include "Gameplay/Board/BoardView.h"

#include "Gameplay/Cell/CellModel.h"
#include "Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace Global;
		using namespace Sound;

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
					board[a][b] = new Cell::CellController(sf::Vector2i(a, b));
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

		void BoardController::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			switch (button_type)
			{
			case UI::UIElement::ButtonType::LEFT_MOUSE_BUTTON:
				openCell(cell_controller->getCellPosition());
				break;

			case UI::UIElement::ButtonType::RIGHT_MOUSE_BUTTON:
				flagCell(cell_controller->getCellPosition());
				break;
			}
		}

		void BoardController::openCell(sf::Vector2i cell_position)
		{
			if (board[cell_position.x][cell_position.y]->canOpenCell())
			{
				board[cell_position.x][cell_position.y]->openCell();
			}
		}

		void BoardController::flagCell(sf::Vector2i cell_position)
		{
			switch (board[cell_position.x][cell_position.y]->getCellState())
			{
			case CellState::FLAGGED:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				flagged_cells--; //Used to update Gameplay UI
				break;

			case CellState::HIDDEN:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				flagged_cells++; //Used to update Gameplay UI
				break;
			}

			board[cell_position.x][cell_position.y]->flagCell();
		}

		int BoardController::getMinesCount()
		{
			return mines_count - flagged_cells;
		}

		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState state)
		{
			board_state = state;
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
			flagged_cells = 0;
			board_state = BoardState::FIRST_CELL;

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