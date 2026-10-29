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

private:
	ModelRender m_modelRender;
	Vector3 m_pos;
};

