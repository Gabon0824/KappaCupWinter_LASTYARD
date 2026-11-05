#pragma once
class Reticle :public IGameObject
{
public:
	Reticle();
	~Reticle();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;
};

