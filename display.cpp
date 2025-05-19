#include "display.h"

#include <Arduino.h>

Display::Display() {
	//lcd = new LiquidCrystal_I2C(0x27, 20, 4);
}

Display::~Display() {
	//delete lcd;
}

void Display::begin() {
	//lcd->init();
	//lcd->backlight();
	clear();
}

void Display::clear() {
	//lcd->setCursor(0, 0);
	blink(false);
	//lcd->clear();
}

void Display::blink(bool state) {
	/*if (state) {
		lcd->blink();
	} else {
		lcd->noBlink();
	}*/
}

void Display::blink() {
	blink(true);
}

void Display::write(int x, int y, char *m) {
	/*lcd->setCursor(x, y);
	lcd->print(m);*/
}

void Display::show(Screen *screen) {
	clear();
	switch (screen->type) {
		case ScreenType::PICK_TIME:
			show((PickTimeScreen*)screen);
			break;
		case ScreenType::QUIZ:
			show((QuizScreen*)screen);
			break;
		default:
			return;
	}
}


void Display::show(PickTimeScreen *picker) {
	// TODO
}

void Display::show(QuizScreen *quiz) {
	// TODO
}
