#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
public:
	Zombie();
	void AttackPlayer(const Vector3& toPlayer) override;
};

