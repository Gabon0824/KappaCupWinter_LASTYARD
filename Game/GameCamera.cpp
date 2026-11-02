#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{

}

GameCamera::~GameCamera()
{

}

bool GameCamera::Start()
{
	toCameraPos.Set(0.0f, 8.0f, -65.0f);
	m_player = FindGO<Player>("player");

	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(10000.0f);
	return true;
}

void GameCamera::Update()
{
	float shiftAmount = 22.0f;
	float distance = 65.0f;
	float viewangle = 60.0f;
	if (g_pad[0]->IsPress(enButtonLB2))
	{
		shiftAmount = 28.0f;
		distance = 40.0f;
		viewangle = 45.0f;
	}
	Vector3 target = m_player->position;
	target.y += 62.0f;

	Vector3 right = g_camera3D->GetRight();
	right.y = 0.0f;
	right.Normalize();
	target += right * shiftAmount;

	Vector3 toCameraPosOld = toCameraPos;

	float x = g_pad[0]->GetRStickXF();
	float y = g_pad[0]->GetRStickYF();
	Quaternion qRot;
	qRot.SetRotationDeg(Vector3::AxisY, 1.3f * x);
	qRot.Apply(toCameraPos);
	//X軸回りの回転
	Vector3 axisX;
	axisX.Cross(Vector3::AxisY, toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 1.3f * y);
	qRot.Apply(toCameraPos);

	Vector3 toPosDir = toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.2f)
	{
		//カメラが上むきすぎ
		toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.9f)
	{
		//カメラが下向きすぎ
		toCameraPos = toCameraPosOld;

	}

	

	Vector3 dir = toCameraPos;
	dir.Normalize();
	Vector3 pos = target + dir * distance;

	g_camera3D->SetViewAngle(Math::DegToRad(viewangle));
	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	g_camera3D->Update();

}
