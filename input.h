#pragma once

#include <OneButton.h>

class ButtonConfig {
	public:
		int pin;
		void (*click)();
		void (*hold)();
		void (*doubl)();
		
		ButtonConfig(int p, void (*c)(), void (*h)(), void (*d)()) 
			: pin(p), click(c), hold(h), doubl(d) {}

		ButtonConfig(int p, void (*c)(), void (*h)()) 
			: pin(p), click(c), hold(h), doubl(nullptr) {}

		ButtonConfig(int p, void (*c)()) 
			: pin(p), click(c), hold(nullptr), doubl(nullptr) {}
};

class ConfiguredButton {
	private:
		OneButton *btn;

	public:
		ConfiguredButton(ButtonConfig c);
		~ConfiguredButton();

		void tick();
};

class Input {
	private:
		ConfiguredButton** btns;
		int size;

	public:
		Input(ButtonConfig **c, int s);
		~Input();

		void tick();
};
