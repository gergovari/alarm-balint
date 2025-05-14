#include <Arduino.h>

#include "speaker.h"
#include "alarm.h"

#include "input.h"

/*
#include <RTClib.h>
RTC_DS3231 rtc;
	DateTime now = rtc.now();
	Serial.print(now.year(), DEC);
*/

Speaker speaker;
Alarm alarm;

#define LEFT 6
#define RIGHT 7
#define OK 8

ButtonConfig left(LEFT, nullptr, nullptr, nullptr);
ButtonConfig right(RIGHT, nullptr, nullptr, nullptr);
ButtonConfig ok(OK, nullptr, nullptr);
ButtonConfig *btns[3] = { &left, &right, &ok };

Input input(btns, 3);

void playAlarm() {
	speaker.setVolume(100);
	speaker.play(Music::ZAMBO);

	Serial.println("Alarm playing!");
}

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
