#pragma once

#include "pick_time_screen.h"
#include "quiz_screen.h"

class PickTimeScreen;
class QuizScreen;

class Display {
	private:
		//LiquidCrystal_I2C *lcd;

	public:
		Display();
		~Display();
		
		void begin();
		void clear();
		void blink(bool state);
		void blink();
		void write(int x, int y, char *m);

		void show(Screen *screen);
		void show(PickTimeScreen *picker);
		void show(QuizScreen *quiz);
};
