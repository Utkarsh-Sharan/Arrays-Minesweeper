#pragma once

#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
        class CellView;
        class CellModel;

        enum class CellState;
        enum class CellValue;

		class CellController
		{
        private:
            CellView* cell_view;
            CellModel* cell_model;

            void destroy();

        public:
            CellController(sf::Vector2i position);
            ~CellController();

            void initialize(float cell_width, float cell_height);
            void update();
            void render();

            bool canOpenCell();
            void openCell();
            void flagCell();

            CellState getCellState();
            void setCellState(CellState state);

            CellValue getCellValue();
            void setCellValue(CellValue value);

            sf::Vector2i getCellPosition();

            void reset();
		};
	}
}