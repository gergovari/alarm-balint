#include "alarm.h"

#include <Arduino.h>

void Alarm::start(long long int time) {
	last = millis();
	target = time;
}

void Alarm::tick() {
	if (millis() > target && target != 0) {
		target = 0;
		cb();
	}
}
