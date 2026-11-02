#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "GameCamera.h"





Game::Game()
{
	map = NewGO<Map>(0);
	player = NewGO<Player>(0, "player");
	gameCamera = NewGO<GameCamera>(0, "gamecamera");
}

Game::~Game()
{
	DeleteGO(map);
	DeleteGO(player);
	DeleteGO(gameCamera);
}

bool Game::Start()
{
	
	return true;
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	
}

void Game::Render(RenderContext& rc)
{
	
}