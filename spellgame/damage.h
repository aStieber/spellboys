#pragma once

enum damageType {fire, ice, poison};

class damage {
public:
	damage();
	damage(float _amount, damageType _type);
	float amount;
	damageType type;
};