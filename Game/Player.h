#pragma once
class  Player : public IGameObject
{
public:
 Player();
 ~Player();
 void Update();
 void Render(RenderContext& rc);
 void Move();
 void Rotation();
 void Animation();

 enum EnAnimationClip
 {
	 enAnimationClip_Idle,
	 enAnimationClip_Aim,
	 enAnimationClip_AimWalk,
	 enAnimationClip_Walk,
	 enAnimationClip_Num,
 };
 AnimationClip animationClips[enAnimationClip_Num];

 ModelRender modelRender;
 Vector3 position;
 CharacterController characterController;
 Vector3 moveSpeed;
 Quaternion rotation;
 float defaultSpeed = 1.0f;
 const int MAX_HP = 100;
 int hp = MAX_HP;

};

