#include "speaker.h"

bool Speaker::begin() {
	softwareSerial.begin(9600);

	if (player.begin(softwareSerial)) {
		setVolume(0);
		return true;
	} else {
		return false;
	}
	
}

void Speaker::setVolume(int val) {
	int vol = map(val, 0, 100, 0, 30);
	player.volume(vol);

}

void Speaker::play(Music music) {
	player.loop(int(music) + 1);

}

void Speaker::stop() {
	player.pause();

}

void Speaker::state() {
	Serial.println(player.readState());
}

void Speaker::files() {
	Serial.println(player.readFileCounts());
}
