#pragma once
class Bullet :public IGameObject
{
public:
	Bullet();
	~Bullet();
	void Update();
	void Render(RenderContext &rc);

	ModelRender modelRender;
	Vector3 pos;
	Vector3 moveSpeed;
	float timer = 0.0f;
};

