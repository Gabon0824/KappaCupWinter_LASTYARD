#include "stdafx.h"
#include "Boss.h"
#include "Game.h"
#include "Player.h"


namespace
{
	const float PLATE_BODY_RATE = 0.3f;
	const float HEART_RADIUS = 15.0f;
	const float CHARGE_TIME = 3.0f;
	const float SHOCK_NEAR = 80.0f;
	const float SHOCK_FAR = 250.0f;
	const int SHOCK_NEAR_DAMAGE = 40;
	const int SHOCK_FAR_DAMAGE = 20;

}
Boss::Boss()
{
	animationClips[enAnimationClip_Walk].Load("Assets/animData/boss_walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Attack].Load("Assets/animData/boss_ground_slam.tka");
	animationClips[enAnimationClip_Attack].SetLoopFlag(true);
	animationClips[enAnimationClip_Idle].Load("Assets/animData/boss_idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Shockwave].Load("Assets/animData/boss_shockwave.tka");
	animationClips[enAnimationClip_Shockwave].SetLoopFlag(true);
	modelRender.Init("Assets/boss/Boss.tkm", animationClips, enAnimationClip_Num);
	modelRender.SetScale(2.5f, 2.5f, 2.5f);
	plateRender.Init("Assets/boss/Boss_Plate.tkm",nullptr,0,enModelUpAxisY);
	plateRender.SetScale(2.5f, 2.5f, 2.5f);
	spineBoneId = modelRender.FindBoneID(L"spine_04");


	MOVE_SPEED = 150.0f;
	MAX_HP = 100.0f;
	hp = MAX_HP;
	Attack = 50;
	ATTACK_RANGE = 100.0f;
	SEACH_RANGE = 800.0f;
	attackTimer = 0.0f;
	AttackCool = 1.0f;

	CAPSULE_RADIUS = 37.5f;
	CAPSULE_HEIGHT = 105.0f;
	HIT_CENTER_HEIGHT = 90.0f;
	HIT_RADIUS = 100.0f;
}

void Boss::Update()
{
	Enemy::Update();

	Bone* handBone = modelRender.GetBone(spineBoneId);

	Vector3 pos;
	Quaternion rot;
	Vector3 scale;
	handBone->CalcWorldTRS(pos, rot, scale);

	plateRender.SetPosition(pos);
	plateRender.SetRotation(rot);
	plateRender.Update();

	Vector3 offset = { 1.47f,-6.97f,-4.0f };
	offset *= 2.5f;
	rot.Apply(offset);
	heartPos = pos + offset;
}

void Boss::Render(RenderContext& rc)
{
	Enemy::Render(rc);
	if (isPlate)
	{
		plateRender.Draw(rc);
	}
}

void Boss::OnHit(const Vector3& hitPos,const Vector3& dir, int damage)
{
	if (isPlate)
	{
		plateHP  -= damage;
		hp -= damage * PLATE_BODY_RATE;
		if (plateHP <= 0)
		{
			isPlate = false;
		}
	}
	else
	{
		Vector3 toHeart = heartPos - hitPos;
		float t = toHeart.Dot(dir);
		Vector3 nearest = hitPos + dir * t;
		Vector3 diff = heartPos - nearest;
		if (diff.Length() < HEART_RADIUS)
		{
			damage *= 1.5f;
		}
		hp -= damage;
	}
}

void Boss::OnDead()
{
	Enemy::OnDead();
	Game* game = FindGO<Game>("game");
	game->gameClear = true;
}

void Boss::AttackPlayer(const Vector3& toPlayer)
{
	// その場で止まる
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	// 攻撃のアニメを流して、プレイヤーの方を向く
	rotation.SetRotationYFromDirectionXZ(toPlayer);
	modelRender.SetRotation(rotation);
	if (attackTimer == 0.0f)
	{
		attackType = rand() % 2;
		if (attackType == 1)
		{
			isShockwave = true;
		}
	}
	if (attackType == 0)
	{
		modelRender.PlayAnimation(enAnimationClip_Attack, 1.0f);
	}
	else
	{
		modelRender.PlayAnimation(enAnimationClip_Shockwave, 1.0f);
	}
	// ためている時間を数える
	attackTimer += g_gameTime->GetFrameDeltaTime();
	// ため終わったら殴る（途中で範囲の外へ逃げると、Enemy::Update でタイマーが 0 に戻る）
	if (attackTimer >= CHARGE_TIME)
	{
		if (attackType == 0)
		{
			player->hp -= Attack;
		}
		else
		{
			float dist = (player->position - position).Length();
			if (dist < SHOCK_NEAR)
			{
				player->hp -= SHOCK_NEAR_DAMAGE;
			}
			else if (dist < SHOCK_FAR)
			{
				player->hp -= SHOCK_FAR_DAMAGE;
			}
			isShockwave = false;
		}
		if (player->hp < 0)
		{
			player->hp = 0;
		}
		attackTimer = 0.0f;
	}
}
