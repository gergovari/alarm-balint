#include "quiz_screen.h"

#include <Arduino.h>

void QuizScreen::left(ScreenManager *manager) {
	selected = constrain(selected - 1, 0, size - 1);
}

void QuizScreen::doubleLeft(ScreenManager *manager) {
	selected = 0;
}

void QuizScreen::right(ScreenManager *manager) {
	selected = constrain(selected + 1, 0, size - 1);
}

void QuizScreen::doubleRight(ScreenManager *manager) {
	selected = size - 1;
}

void QuizScreen::ok(ScreenManager *manager) {
	auto func = funcs[constrain(selected, 0, size - 1)];
	if (func) func();
}
