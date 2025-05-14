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
	// TODO
}

void Speaker::play(Music music) {
	// TODO
	//player.play(2);
}
