#pragma once

enum damageType {fire, ice, poison};

class damage {
public:
	float amount;
	damageType type;
};