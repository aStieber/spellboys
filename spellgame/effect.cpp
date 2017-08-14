#include "effect.h"

effect::effect() {}



using namespace std::chrono;
bool effect::isExpired() {
	return (duration_cast<milliseconds>(system_clock::now().time_since_epoch()) >= Timer_End);
}

void effect::setDuration(float f) {
	Timer_End = duration_cast<milliseconds>(system_clock::now().time_since_epoch()) + milliseconds((int)(f * 1000));
}