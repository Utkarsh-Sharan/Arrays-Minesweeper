#include "Gameplay/Cell/CellController.h"
#include "Gameplay/Cell/CellView.h"
#include "Gameplay/Cell/CellModel.h"

#include "Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Cell
	{
		using namespace Global;
		using namespace Sound;

		CellController::CellController(sf::Vector2i position)
		{
			cell_view = new CellView(this);
			cell_model = new CellModel(position);
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize(float cell_width, float cell_height)
		{
			cell_view->initialize(cell_width, cell_height);
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

		bool CellController::canOpenCell()
		{
			return getCellState() != CellState::FLAGGED && getCellState() != CellState::OPEN;
		}

		void CellController::openCell()
		{
			setCellState(CellState::OPEN);

			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		}

		void CellController::flagCell()
		{
			switch (cell_model->getCellState())
			{
			case CellState::FLAGGED:
				setCellState(CellState::HIDDEN);
				break;

			case CellState::HIDDEN:
				setCellState(CellState::FLAGGED);
				break;
			}

			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
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

		sf::Vector2i CellController::getCellPosition()
		{
			return cell_model->getCellPosition();
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