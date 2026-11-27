#include "stdafx.h"
#include "Zombie.h"
#include "Player.h"


namespace
{
	const  float GRAB_TIME = 2.4f;
	const float BITE_TIME = 1.2f;
	const int BITE_DAMAGE = 20;
	const float STAGGER_TIME = 1.0f;
	const float GRAB_DISTANCE = 30.0f;
}
Zombie::Zombie()
{
	animationClips[enAnimationClip_Walk].Load("Assets/animData/human_zombie_walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Attack].Load("Assets/animData/human_zombie_attack.tka");
	animationClips[enAnimationClip_Attack].SetLoopFlag(true);
	animationClips[enAnimationClip_Idle].Load("Assets/animData/human_zombie_idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	modelRender.Init("Assets/enemy/Zombie.tkm", animationClips, enAnimationClip_Num);

	MOVE_SPEED = 120.0f;
	MAX_HP = 30.0f;
	hp = MAX_HP;
	Attack =20;
	ATTACK_RANGE = 70.0f;
	SEACH_RANGE = 400.0f;
	attackTimer = 0.0f;
	AttackCool = 1.0f;
	CAPSULE_RADIUS = 15.0f;
	CAPSULE_HEIGHT = 42.0f;
	HIT_CENTER_HEIGHT = 36.0f;
	HIT_RADIUS = 40.0f;
}

void Zombie::AttackPlayer(const Vector3& toPlayer)
{
	
	// その場で止まる
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	if (staggerTimer > 0.0f)
	{
		staggerTimer -= g_gameTime->GetFrameDeltaTime();
		return;
	}
	if (isGrab == false)
	{
		// まだつかんでいない → だれもつかまれていなければ、つかみ始める
		if (player->isGrabbed == false)
		{
			Vector3 toZombie = position - player->position;
			toZombie.y = 0.0f;
			toZombie.Normalize();

			player->rotation.SetRotationYFromDirectionXZ(toZombie);
			player->modelRender.SetRotation(player->rotation);

			position = player->position + toZombie * GRAB_DISTANCE;
			characterController.SetPosition(position);
			modelRender.SetPosition(position);

			rotation.SetRotationYFromDirectionXZ(toZombie * -1.0f);
			modelRender.SetRotation(rotation);
			isGrab = true;
			isBite = false;
			player->isGrabbed = true;
			grabTimer = 0.0f;
		}
	}
	else
	{
		// つかみ中 → 時間を数えて、放す時間になったら両方戻す
		grabTimer += g_gameTime->GetFrameDeltaTime();
		if (grabTimer >= BITE_TIME && isBite == false)
		{
			player->hp -= BITE_DAMAGE;

			if (player->hp < 0)
			{
				player->hp = 0;
			}
			isBite = true;
		}
			if (grabTimer >= GRAB_TIME)
			{
				isGrab = false;
				player->isGrabbed = false;
				staggerTimer = STAGGER_TIME;
			}
		}
	}
