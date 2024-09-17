#include "Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel()
		{

		}

		CellModel::~CellModel() = default;

		void CellModel::initialize()
		{

		}

		void CellModel::update()
		{

		}

		void CellModel::render()
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

		void CellModel::reset()
		{
			cell_value = CellValue::EMPTY;
			cell_state = CellState::HIDDEN;
		}
	}
}