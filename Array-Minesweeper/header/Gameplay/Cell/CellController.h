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
            CellController(int index);
            ~CellController();

            void initialize(float cell_width, float cell_height);
            void update();
            void render();

            CellState getCellState();
            void setCellState(CellState state);

            CellValue getCellValue();
            void setCellValue(CellValue value);

            int getCellIndex();

            void reset();
		};
	}
}