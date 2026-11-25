#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Map;
class GameCamera;
class Pistol;
class Reticle;
class UI;
class Enemy;
class Boss;

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
	Enemy* enemy;
	Boss* boss;
	bool gameClear = false;
	bool gameOver = false;
	int enemyCount = 0;
	int defeatCount = 0;

private:
	
	Vector3 m_pos;
};

