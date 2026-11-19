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
	virtual void AttackPlayer(const Vector3& toPlayer);
	ModelRender modelRender;
	enum EnAnimationClip
	{
		enAnimationClip_Walk,
		enAnimationClip_Attack,
		enAnimationClip_Idle,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	Vector3 position;
	Player* player = nullptr;
	CharacterController characterController;
	Vector3 moveSpeed;
	Quaternion rotation;

	float MOVE_SPEED;
	int MAX_HP;
	int hp;
	int Attack;
	float ATTACK_RANGE;
	float SEACH_RANGE;
	float attackTimer = 0.0f;
	float AttackCool;

};

