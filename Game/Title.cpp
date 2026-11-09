#include "stdafx.h"
#include "Title.h"
#include "Game.h"
Title::Title()
{
	modelRender.Init("Assets/stage/yard/YardMap.tkm");

	spriteRender.Init("Assets/sprite/Title_Logo.DDS", 1024, 256);
	spriteRender.SetPosition(Vector3(0.0f, 230.0f, 0.0f));
	spriteRender.Update();

	fontRender.SetPosition(Vector3(-90.0f, -320.0f, 0.0f));
	fontRender.SetText(L"PRESS A");

	g_camera3D->SetFar(10000.0f);
}

Title::~Title()
{

}

void Title::Update()
{
	float deltaTime = g_gameTime->GetFrameDeltaTime();
	CameraRotate += deltaTime* 4;
	
	float radian = Math::DegToRad(CameraRotate);

	Vector3 target(0.0f, 100.0f, 1500.0f);
	Vector3 pos;
	pos.x = target.x + sin(radian) * 1500.0f;

	pos.y = 1000.0f;

	pos.z = target.z + cos(radian) * 1800.0f;

	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	g_camera3D->Update();

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
	spriteRender.Draw(rc);
	fontRender.Draw(rc);
}
