#pragma once

class Player;
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	ModelRender modelRender;
	enum EnAnimationClip
	{
		enAnimationClip_Walk,
		enAnimationClip_Attack,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	Vector3 position;
	Player* player = nullptr;
	CharacterController characterController;
	Vector3 moveSpeed;
	Quaternion rotation;

	const float MOVE_SPEED = 60.0f;
	const int MAX_HP = 30;
	int hp = MAX_HP;
	int Attack = 20;
	const float ATTACK_RANGE = 70.0f;
	float attackTimer = 0.0f;
	float AttackCool = 1.0f;

};

