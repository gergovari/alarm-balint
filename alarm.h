#pragma once

class Alarm {
	private:
		long long int target;
		long long int last;

	public:
		void (*cb)();

		void start(long long int time);
		void tick();
};
