#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);

	ModelRender modelRender;
	SpriteRender spriteRender;
	FontRender fontRender;
	float CameraRotate = 0;

};

