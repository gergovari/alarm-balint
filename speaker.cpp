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
	int vol = map(val, 0, 100, 0, 30);
	player.volume(vol);

}

void Speaker::play(Music music) {
	// TODO
	//player.play(2);
	player.play(int(music) + 1);

}
