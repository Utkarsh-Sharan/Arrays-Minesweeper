#pragma once

#include "Gameplay/Cell/CellController.h"
#include "Gameplay/Board/BoardController.h"
#include "UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardController;
		class CellController;

		class BoardService
		{
		private:
			BoardController* board_controller;

			void destroy();

		public:
			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();

			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);

			int getMinesCount();

			void showBoard();
			void setBoardState(BoardState state);

			void resetBoard();
		};
	}
}