#include "stdafx.h"
#include "Bullet.h"
#include "Enemy.h"

namespace
{
	const float  BULLET_LIFE_TIME = 2.0f;
	const int BULLET_DAMAGE = 10;
	const float HIT_DISTANCE = 40.0f;
	const float HEAD_HEIGHT = 64.0f;
	const float HEAD_DISTANCE = 12.0f;

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
		Vector3 HeadPosition = enemy->position;
		HeadPosition.y += HEAD_HEIGHT;
		Vector3 HeadDistance = HeadPosition - pos;
		if (diff.Length() < HIT_DISTANCE)
		{
			int damage = BULLET_DAMAGE;
			int random = rand() % 100;
			if (random < 3)
			{
				enemy->hp = 0;
			}
			else if (HeadDistance.Length() < HEAD_DISTANCE)
			{
				damage *= 1.5;
			}
			enemy->hp -= damage;
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