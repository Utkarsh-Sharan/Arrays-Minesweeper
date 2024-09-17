#pragma once

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
        enum class CellState
        {
            HIDDEN,
            OPEN,
            FLAGGED,
        };

        enum class CellValue
        {
            EMPTY,
            ONE,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            MINE,
        };

		class CellModel
		{
        private:
            sf::Vector2i position;

            CellState cell_state;
            CellValue cell_value;

        public:
            CellModel(sf::Vector2i position);
            ~CellModel();

            void initialize();
            void update();

            CellState getCellState();
            void setCellState(CellState state);

            CellValue getCellValue();
            void setCellValue(CellValue value);

            sf::Vector2i getCellIndex();

            void reset();
		};
	}
}