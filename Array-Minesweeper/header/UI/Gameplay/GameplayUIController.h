#pragma once

#include "UI/Interface/IUIController.h"

#include "UI/UIElement/TextView.h"

namespace UI
{
	namespace Gameplay
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const int font_size = 110;
			const sf::Color text_color = sf::Color::Red;

			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;

			UIElement::TextView* time_text;

			void createTexts();
			void initializeTexts();
			void initializeTimeText();
			void updateTimeText();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize();
			void update();
			void render();

			void show();
		};
	}
}