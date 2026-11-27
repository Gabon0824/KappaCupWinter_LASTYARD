#pragma once
#include "Enemy.h"
class Boss : public Enemy
{
public:
	Boss();
	void Update();
	void Render(RenderContext& rc);
	ModelRender plateRender;
	int spineBoneId = -1;
	void OnHit(const Vector3& hitpos,const Vector3& dir, int damage);
	int plateHP = 50;
	bool isPlate = true;
	Vector3 heartPos;
	void OnDead() override;
	void AttackPlayer(const Vector3& toPlayer) override;
	bool isShockwave = false;
	bool Impact() override { return isShockwave; }
	int attackType = 0;

};
