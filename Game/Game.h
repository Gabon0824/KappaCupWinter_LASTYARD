#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Map;
class GameCamera;
class Pistol;
class Reticle;
class UI;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	Map* map;
	Player* player;
	GameCamera* gameCamera;
	Pistol* pistol;
	Reticle* reticle;
	UI* ui;

private:
	
	Vector3 m_pos;
};

