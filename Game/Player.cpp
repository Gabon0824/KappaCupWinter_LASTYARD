#include "stdafx.h"
#include "Player.h"
#include "Game.h"

Player::Player()
{
	modelRender.Init("Assets/Chara_wepon/Human.tkm");

	characterController.Init(25.0f, 75.0f, position);

}

Player::~Player()
{

}

void Player::Update()
{
	Move();
	Rotation();
	modelRender.Update();

}

void Player::Move()
{
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックの入力量
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y方向には移動させない
	forward.y = 0.0f;
	right.y = 0.0f;

	//左スティックの入力量と120.0ｆを乗算
	right *= stickL.x * 120.0f * defaultSpeed;;
	forward *= stickL.y * 120.0f * defaultSpeed;;

	//左スティックの入力量を加算する
	moveSpeed += right + forward;

	if (g_pad[0]->IsPress(enButtonLB2))
	{
		moveSpeed.x *= 0.7f;
		moveSpeed.z *= 0.7f;
	}

	else if(g_pad[0]->IsPress(enButtonB))
	{
		moveSpeed.x *= 3.0f;
		moveSpeed.z *= 3.0f;
	}


	//地面についてたら
	if (characterController.IsOnGround())
	{
		//重力を直す
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			moveSpeed.y = 210.0f;
		}
	}

	//地面についてなかったら
	else
	{
		//重力を発生させる
		moveSpeed.y -= 5.0f;

	}
	if(position.y <= -500.0f)
	{
		position = { 0.0f,0.0f,0.0f };
		characterController.SetPosition(position);
	}

	//キャラクターコントローラーを使って座標を移動する
	position = characterController.Execute(moveSpeed,1.0f / 60.0f);
	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//移動方向を向く
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		modelRender.SetRotation(rotation);
	}
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}


