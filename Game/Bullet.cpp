#include "stdafx.h"
#include "Bullet.h"



namespace
{
	const float  BULLET_LIFE_TIME = 2.0f;
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


	Vector3 dir = moveSpeed;
	dir.Normalize();
	Quaternion rot;
	rot.SetRotation(Vector3::AxisZ, dir);

	modelRender.SetPosition(pos);
	modelRender.SetRotation(rot);
	modelRender.Update();

	
}
void Bullet::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}