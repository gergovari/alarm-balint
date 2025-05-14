#pragma once

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

enum class Music {
	CYBERPUNK,
	ZAMBO
};

class Speaker {
	private:
		SoftwareSerial softwareSerial;
		DFRobotDFPlayerMini player;
	public:
		Speaker() : softwareSerial(3, 2) {};
		bool begin();

		void setVolume(int val);
		void play(Music music);
};
