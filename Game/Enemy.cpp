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
	modelRender.Init("Assets/enemy/Zombie.tkm", animationClips, enAnimationClip_Num);
	position.z = 300.0f;
	modelRender.SetPosition(position);
	characterController.Init(15.0f, 42.0f, position);
}

Enemy::~Enemy()
{
	
}

bool Enemy::Start()
{
	player = FindGO<Player>("player");
	return true;
}

void Enemy::Update()
{
	if (hp <= 0)
	{
		Game* game = FindGO<Game>("game");
		game->gameClear = true;
		DeleteGO(this);
		return;
	};
	//プレイヤーへの向きをだす
	Vector3 toPlayer = player->position - position;
	float distance = toPlayer.Length();
	toPlayer.y = 0.0f;
	toPlayer.Normalize();
	
	if (distance > ATTACK_RANGE)
	{
		moveSpeed = toPlayer * MOVE_SPEED;
		modelRender.PlayAnimation(enAnimationClip_Walk, 0.2f);
		attackTimer = 0.0f;
	}
	else
	{
		moveSpeed.x = 0.0f;
		moveSpeed.z = 0.0f;
		modelRender.PlayAnimation(enAnimationClip_Attack, 1.5f);
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

	rotation.SetRotationYFromDirectionXZ(toPlayer);
	modelRender.SetRotation(rotation);

	modelRender.Update();
}

void Enemy::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}
