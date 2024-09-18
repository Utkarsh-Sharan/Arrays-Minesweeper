#pragma once

#include "Gameplay/Cell/CellController.h"
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

			int getMinesCount();

			void reset();

		private:
			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];

			void createBoard();
			void initializeCells();

			void destroy();
			void deleteBoard();
			void resetBoard();
		};
	}
}