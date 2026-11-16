#pragma once
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	void Update();
	void Render(RenderContext& rc);

	ModelRender modelRender;
	SpriteRender spriteRender;
	SpriteRender clearRender;
	FontRender fontRender;
	FontRender pressText;
	SpriteRender restartRender;
	SpriteRender menuRender;
	SpriteRender cursorRender;
	int Select = 0;
};

