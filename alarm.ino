#include <Arduino.h>

#include "speaker.h"

/*
#include <RTClib.h>
RTC_DS3231 rtc;
	DateTime now = rtc.now();
	Serial.print(now.year(), DEC);
*/

Speaker speaker;

void setup() {
	Serial.begin(9600);
	speaker.begin();

	speaker.setVolume(100);
	speaker.play(Music::ZAMBO);
	Serial.println(int(Music::ZAMBO));

}

void loop() {
}
