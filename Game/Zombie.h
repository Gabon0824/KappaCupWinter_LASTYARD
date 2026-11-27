#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
public:
	Zombie();
	void AttackPlayer(const Vector3& toPlayer)override;
	bool Impact() override { return isGrab || staggerTimer > 0.0f; }
	bool isGrab = false;
	float grabTimer = 0.0f;
	bool isBite = false;
	float staggerTimer = 0.0f;
};

