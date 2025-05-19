#pragma once

#include "screen.h"
#include "screen_manager.h"

class QuizScreen : public Screen {
	public:
		char **names;
		void (**funcs)();
		int size;
		int selected = 0;

		QuizScreen(char **n, void (**f)(), int s) : Screen(ScreenType::QUIZ), names(n), funcs(f), size(s) {};

		void left(ScreenManager *manager);
		void right(ScreenManager *manager);
		void ok(ScreenManager *manager);

		void doubleLeft(ScreenManager *manager);
		void doubleRight(ScreenManager *manager);
};
