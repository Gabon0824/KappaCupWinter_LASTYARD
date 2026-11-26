#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"


namespace
{
	const float HEAD_HEIGHT = 64.0f;
	const float HEAD_DISTANCE = 12.0f;
}
Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
	
}

bool Enemy::Start()
{
	player = FindGO<Player>("player");
	modelRender.SetPosition(position);
	characterController.Init(CAPSULE_RADIUS, CAPSULE_HEIGHT, position);
	return true;
}

void Enemy::Update()
{
	if (hp <= 0)
	{
		OnDead();
		DeleteGO(this);
		return;
	};
	//プレイヤーへの向きをだす
	Vector3 toPlayer = player->position - position;
	float distance = toPlayer.Length();
	toPlayer.y = 0.0f;
	toPlayer.Normalize();
	if (distance > SEACH_RANGE)
	{
		moveSpeed.x = 0.0f;
		moveSpeed.z = 0.0f;
		modelRender.PlayAnimation(enAnimationClip_Idle, 0.2f);
	}
	else if (distance > ATTACK_RANGE)
	{
		moveSpeed = toPlayer * MOVE_SPEED;
		modelRender.PlayAnimation(enAnimationClip_Walk, 0.2f);
		attackTimer = 0.0f;
		rotation.SetRotationYFromDirectionXZ(toPlayer);
		modelRender.SetRotation(rotation);
	}
	else
	{
		AttackPlayer(toPlayer);
	}
	
	

	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	modelRender.SetPosition(position);

	

	modelRender.Update();
}

void Enemy::AttackPlayer(const Vector3& toPlayer)
	{
		moveSpeed.x = 0.0f;
		moveSpeed.z = 0.0f;
		modelRender.PlayAnimation(enAnimationClip_Attack, 1.0f);
		rotation.SetRotationYFromDirectionXZ(toPlayer);
		modelRender.SetRotation(rotation);
		attackTimer += g_gameTime->GetFrameDeltaTime();
		if (attackTimer >= AttackCool)
		{
			player->hp -= Attack;
			if (player->hp < 0)
			{
				player->hp = 0;
			}
			attackTimer = 0.0f;
		}
}

void Enemy::OnHit(const Vector3& hitPos,const Vector3& dir, int damage)
{
	//ヘッド判定
	Vector3 HeadPosition = position;
	HeadPosition.y += HEAD_HEIGHT;
	Vector3 HeadDistance = HeadPosition - hitPos;
	{
		//３パーで一撃
		int random = rand() % 100;
		if (random < 3)
		{
			hp = 0;
		}
		//頭で1.5倍
		else if (HeadDistance.Length() < HEAD_DISTANCE)
		{
			damage *= 1.5;
		}
		hp -= damage;
	}
}
void Enemy::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}

void Enemy::OnDead()
{
	Game* game = FindGO<Game>("game");
	game->defeatCount++;
}
