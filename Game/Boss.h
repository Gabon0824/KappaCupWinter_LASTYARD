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
	void OnHit(const Vector3& hitpos, int damage);
	int plateHP = 50;
	bool isPlate = true;

};
