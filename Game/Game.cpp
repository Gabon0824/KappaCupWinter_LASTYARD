#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "GameCamera.h"
#include "Pistol.h"
#include "Reticle.h"





Game::Game()
{
	map = NewGO<Map>(0);
	player = NewGO<Player>(0, "player");
	gameCamera = NewGO<GameCamera>(0, "gamecamera");
	pistol = NewGO<Pistol>(0, "pistol");
	reticle = NewGO<Reticle>(0, "reticle");
}

Game::~Game()
{
	DeleteGO(map);
	DeleteGO(player);
	DeleteGO(gameCamera);
	DeleteGO(pistol);
	DeleteGO(reticle);
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