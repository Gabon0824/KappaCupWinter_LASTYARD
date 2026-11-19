#include "stdafx.h"
#include "Zombie.h"

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
}

