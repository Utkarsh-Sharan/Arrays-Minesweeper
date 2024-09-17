#include "Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel(sf::Vector2i position)
		{
			this->position = position;
			reset();
		}

		CellModel::~CellModel() = default;

		void CellModel::initialize()
		{

		}

		void CellModel::update()
		{

		}

		CellState CellModel::getCellState()
		{
			return cell_state;
		}

		void CellModel::setCellState(CellState state)
		{
			cell_state = state;
		}

		CellValue CellModel::getCellValue()
		{
			return cell_value;
		}

		void CellModel::setCellValue(CellValue value)
		{
			cell_value = value;
		}

		sf::Vector2i CellModel::getCellIndex()
		{
			return position;
		}

		void CellModel::reset()
		{
			cell_value = CellValue::EMPTY;
			cell_state = CellState::HIDDEN;
		}
	}
}