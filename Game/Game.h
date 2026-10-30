#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Map;

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

private:
	
	Vector3 m_pos;
};

