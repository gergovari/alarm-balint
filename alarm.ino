#include <Arduino.h>

#include "speaker.h"
#include "alarm.h"

/*
#include <RTClib.h>
RTC_DS3231 rtc;
	DateTime now = rtc.now();
	Serial.print(now.year(), DEC);
*/

Speaker speaker;
Alarm alarm;

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
	alarm.tick();
}
