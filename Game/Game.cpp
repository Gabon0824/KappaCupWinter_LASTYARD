#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"





Game::Game()
{
	map = NewGO<Map>(0);
	player = NewGO<Player>(0, "player");
}

Game::~Game()
{
	DeleteGO(map);
	DeleteGO(player);
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