#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "GameCamera.h"
#include "Pistol.h"
#include "Reticle.h"
#include "UI.h"
#include "Enemy.h"
#include "Zombie.h"
#include "GameClear.h"
#include "GameOver.h"




Game::Game()
{
	map = NewGO<Map>(0);
	player = NewGO<Player>(0, "player");
	gameCamera = NewGO<GameCamera>(0, "gamecamera");
	pistol = NewGO<Pistol>(0, "pistol");
	reticle = NewGO<Reticle>(0, "reticle");
	ui = NewGO<UI>(0, "ui");
	Vector3 enemyPositions[] = {
		Vector3(976.0f, 0.0f, -64.0f),
		Vector3(1024.0f, 0.0f, 608.0f),
		Vector3(1120.0f, 0.0f, 1080.0f),
		Vector3(-16.0f, 0.0f, 1032.0f),
		Vector3(-696.0f, 0.0f, 1032.0f),
		Vector3(-1104.0f, 0.0f, 1400.0f),
		Vector3(-208.0f, 0.0f, 1616.0f),
		Vector3(968.0f, 0.0f, 1632.0f),
		Vector3(560.0f, 0.0f, 2584.0f),
		Vector3(-872.0f, 0.0f, 2360.0f)
	};
	for (const Vector3& pos : enemyPositions)
	{
		enemy = NewGO<Zombie>(0, "enemy");
		enemy->position = pos;
		enemyCount++;
	}
}

Game::~Game()
{
	DeleteGO(map);
	DeleteGO(player);
	DeleteGO(gameCamera);
	DeleteGO(pistol);
	DeleteGO(reticle);
	DeleteGO(ui);
	const auto& enemies = FindGOs<Enemy>("enemy");
	for (Enemy* e : enemies)
	{
		DeleteGO(e);
	}
}

bool Game::Start()
{
	g_sceneLight->GetSceneLight().directionalLight[0].castShadow = false;
	return true;
}

void Game::Update()
{
	if (gameClear)
	{
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}
	if (gameOver)
	{
		NewGO<GameOver>(0, "gameover");
		DeleteGO(this);
	}
	 g_renderingEngine->DisableRaytracing();
	
}

void Game::Render(RenderContext& rc)
{
	
}