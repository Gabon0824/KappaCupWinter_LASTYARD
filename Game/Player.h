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

 ModelRender modelRender;
 Vector3 position;
 CharacterController characterController;
 Vector3 moveSpeed;
 Quaternion rotation;
 float defaultSpeed = 1.0f;

};

