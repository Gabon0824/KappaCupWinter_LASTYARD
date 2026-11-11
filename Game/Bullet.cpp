#include "stdafx.h"
#include "Bullet.h"
#include "Enemy.h"

namespace
{
	const float  BULLET_LIFE_TIME = 2.0f;
	const int BULLET_DAMAGE = 10;
	const float HIT_DISTANCE = 40.0f;

}
Bullet::Bullet()
{
	modelRender.Init("Assets/bullet/Bullet.tkm");
}

Bullet::~Bullet()
{

}
void Bullet::Update()
{
	float deltaTime = g_gameTime->GetFrameDeltaTime();

	pos += moveSpeed * deltaTime;

	timer += deltaTime;
	if (timer >= BULLET_LIFE_TIME)
	{
		DeleteGO(this);
		return;
	}
	Enemy* enemy = FindGO<Enemy>("enemy");
	if (enemy != nullptr)
	{
		Vector3 enemyCenter = enemy->position;
		enemyCenter.y += 36.0f;
		Vector3 diff = enemyCenter - pos;
		if (diff.Length() < HIT_DISTANCE)
		{
			enemy->hp -= BULLET_DAMAGE;
			DeleteGO(this);
			return;
		}
	}


	Vector3 dir = moveSpeed;
	dir.Normalize();
	Quaternion rot;
	rot.SetRotation(Vector3::AxisZ, dir);

	modelRender.SetPosition(pos);
	modelRender.SetRotation(rot);
	//弾のサイズ
	Vector3 Size = { 10.0f,10.0f,10.0f };
	modelRender.SetScale(Size);
	modelRender.Update();

	
}
void Bullet::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}