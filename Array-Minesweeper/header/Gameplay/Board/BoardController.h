#pragma once

#include "Gameplay/Cell/CellController.h"
#include "UI/UIElement/ButtonView.h"

#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Board
	{
		class BoardView;

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

			int getMinesCount();

			void reset();

		private:
			int flagged_cells = 0;

			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];

			void createBoard();
			void initializeCells();

			void openCell(sf::Vector2i cell_position);
			void flagCell(sf::Vector2i cell_position);

			void destroy();
			void deleteBoard();
			void resetBoard();
		};
	}
}