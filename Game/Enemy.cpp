#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"

Enemy::Enemy()
{
	animationClips[enAnimationClip_Walk].Load("Assets/animData/human_zombie_walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Attack].Load("Assets/animData/human_zombie_attack.tka");
	animationClips[enAnimationClip_Attack].SetLoopFlag(true);
	animationClips[enAnimationClip_Idle].Load("Assets/animData/human_zombie_idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	modelRender.Init("Assets/enemy/Zombie.tkm", animationClips, enAnimationClip_Num);
}

Enemy::~Enemy()
{
	
}

bool Enemy::Start()
{
	player = FindGO<Player>("player");
	modelRender.SetPosition(position);
	characterController.Init(15.0f, 42.0f, position);
	return true;
}

void Enemy::Update()
{
	if (hp <= 0)
	{
		Game* game = FindGO<Game>("game");
		game->defeatCount++;
		if (game->defeatCount >= game->enemyCount)
		{
			game->gameClear = true;
		}
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
	

	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	modelRender.SetPosition(position);

	

	modelRender.Update();
}

void Enemy::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}
