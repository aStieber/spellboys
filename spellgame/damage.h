#pragma once

enum damageType {Fire, Ice, Poison};

class damage {
public:
	damage();
	damage(float _amount, damageType _type);
	float amount;
	damageType type;
};