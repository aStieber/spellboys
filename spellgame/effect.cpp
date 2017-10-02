#include "effect.h"

effect::effect() {}

bool effect::isExpired() {
	return (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()) >= Timer_End);
}

void effect::setDuration(float f) {
	Timer_End = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()) + std::chrono::milliseconds((int)(f * 1000));
}
