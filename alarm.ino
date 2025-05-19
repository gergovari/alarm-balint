#include <Arduino.h>

#include "speaker.h"
#include "alarm.h"

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

void okClick() {
	Serial.println("OK click");
}

void playAlarm() {
	speaker.setVolume(100);
	speaker.play(Music::ZAMBO);

	Serial.println("Alarm playing!");
}

ButtonConfig left(LEFT, nullptr, nullptr, nullptr);
ButtonConfig right(RIGHT, nullptr, nullptr, nullptr);
ButtonConfig ok(OK, okClick, nullptr);
ButtonConfig *btns[3] = { &left, &right, &ok };

Input input(btns, 3);

void setup() {
	Serial.begin(9600);
	speaker.begin();

	alarm.cb = playAlarm;
	alarm.start(5 * 1000);
}

void loop() {
	input.tick();
	alarm.tick();
}
