#include "Gameplay/Cell/CellController.h"
#include "Gameplay/Cell/CellView.h"
#include "Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController()
		{
			cell_view = new CellView(this);
			cell_model = new CellModel();
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize()
		{
			cell_view->initialize();
			cell_model->initialize();
		}

		void CellController::update()
		{
			cell_view->update();
			cell_model->update();
		}

		void CellController::render()
		{
			cell_view->render();
		}

		CellState CellController::getCellState()
		{
			return cell_model->getCellState();
		}

		void CellController::setCellState(CellState state)
		{
			cell_model->setCellState(state);
		}

		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}

		void CellController::setCellValue(CellValue value)
		{
			cell_model->setCellValue(value);
		}

		void CellController::reset()
		{
			cell_model->reset();
		}

		void CellController::destroy()
		{
			cell_view = nullptr;
			cell_model = nullptr;

			delete (cell_view);
			delete (cell_model);
		}
	}
}