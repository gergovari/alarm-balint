#include <Arduino.h>

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#include <RTClib.h>

SoftwareSerial softwareSerial(3, 2);
DFRobotDFPlayerMini player;

RTC_DS3231 rtc;

void setup() {
	Serial.begin(9600);
	softwareSerial.begin(9600);

	/*if (player.begin(softwareSerial)) {
		Serial.println("Player ready.");
	} else {
		Serial.println("Player failed.");
	}*/

	player.volume(5);
}

int i = 0;

void loop() {
	DateTime now = rtc.now();
	Serial.print(now.year(), DEC);

	player.play(2);
	delay(100000);
}
