#pragma once

class Pistol;
class UI : public IGameObject
{
public:
	UI();
	~UI();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender healthFrame;
	SpriteRender healthBar;
	SpriteRender healthTicks;
	SpriteRender weponPanel;
	SpriteRender medkitPanel;

	FontRender magazineText;;
	FontRender ammoText;
	FontRender medkitText;

	Pistol* pistol = nullptr;


};

