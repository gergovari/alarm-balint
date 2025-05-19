#include <Arduino.h>

#include "speaker.h"
#include "alarm.h"

#include "display.h"
#include "screen_manager.h"

#include "input.h"
#include "input_conf.h"

/* TODO:
	- input (did it work? I don't remember...)

	- screen
	- menu system

	- quiz generator
	- quiz menu
*/

Speaker speaker;
Alarm alarm;

void playAlarm() {
	speaker.setVolume(100);
	speaker.play(Music::ZAMBO);

	Serial.println("Alarm playing!");
}


Display disp;
ScreenManager screenManager(&disp);

void leftClick() {
	screenManager.left();
}
void rightClick() {
	screenManager.right();
}
void okClick() {
	screenManager.ok();
}
void okHold() {
	screenManager.back();
}
void doubleLeftClick() {
	screenManager.doubleLeft();
}
void doubleRightClick() {
	screenManager.doubleRight();
}

ButtonConfig left(LEFT, leftClick, nullptr, doubleLeftClick);
ButtonConfig right(RIGHT, rightClick, nullptr, doubleRightClick);
ButtonConfig ok(OK, okClick, okHold);
ButtonConfig *btns[3] = { &left, &right, &ok };

Input input(btns, 3);

void setup() {
	Serial.begin(9600);
	speaker.begin();

	alarm.cb = playAlarm;
	alarm.start(5 * 1000);

	//screenManager.current = &start;
	//disp.show(screenManager.current);
}

void loop() {
	input.tick();
	alarm.tick();
}
