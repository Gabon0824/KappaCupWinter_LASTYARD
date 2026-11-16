#pragma once
class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender bgRender;
	SpriteRender logoRender;
	SpriteRender restartRender;
	SpriteRender menuRender;
	SpriteRender cursorRender;
	int Select = 0;
};

