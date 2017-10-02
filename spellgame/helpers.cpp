#include "helpers.h"

float getDistanceBetweenPoints(sf::Vector2f _a, sf::Vector2f _b) {
	return(sqrtf((_a.x - _b.x) * (_a.x - _b.x) + (_a.y - _b.y) * (_a.y - _b.y))); //pythagorean
}