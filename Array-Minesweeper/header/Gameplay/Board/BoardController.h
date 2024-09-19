#pragma once

#include "Gameplay/Cell/CellController.h"
#include "UI/UIElement/ButtonView.h"

#include <sfml/Graphics.hpp>
#include <random>

namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		enum class BoardState
		{
			FIRST_CELL,       // The state when the player opens first cell.
			PLAYING,          // The game is in progress.
			COMPLETED,		  // The game is over.
		};

		class BoardController
		{
		public:
			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mines_count = 8;

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();

			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
			void processCellValue(sf::Vector2i cell_position);
			void processEmptyCell(sf::Vector2i cell_position);
			void openEmptyCells(sf::Vector2i cell_position);
			void processMineCell(sf::Vector2i cell_position);

			void openAllCells();

			int getMinesCount();

			BoardState getBoardState();
			void setBoardState(BoardState state);

			void reset();

		private:
			int flagged_cells = 0;

			// To generate random values.
			std::default_random_engine random_engine;
			// To give random seed to generator.
			std::random_device random_device;

			BoardState board_state;
			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];

			void createBoard();
			void initializeCells();

			void openCell(sf::Vector2i cell_position);
			void flagCell(sf::Vector2i cell_position);

			void populateBoard(sf::Vector2i cell_position);
			void populateMines(sf::Vector2i cell_position);
			void populateCells();
			int countMinesAround(sf::Vector2i cell_position);
			bool isValidCellPosition(sf::Vector2i cell_position);

			void destroy();
			void deleteBoard();
			void resetBoard();
		};
	}
}