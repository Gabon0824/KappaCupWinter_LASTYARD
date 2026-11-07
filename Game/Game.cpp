#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "GameCamera.h"
#include "Pistol.h"
#include "Reticle.h"
#include "UI.h"
#include "Enemy.h"




Game::Game()
{
	map = NewGO<Map>(0);
	player = NewGO<Player>(0, "player");
	gameCamera = NewGO<GameCamera>(0, "gamecamera");
	pistol = NewGO<Pistol>(0, "pistol");
	reticle = NewGO<Reticle>(0, "reticle");
	ui = NewGO<UI>(0, "ui");
	NewGO<Enemy>(0, "enemy");
}

Game::~Game()
{
	DeleteGO(map);
	DeleteGO(player);
	DeleteGO(gameCamera);
	DeleteGO(pistol);
	DeleteGO(reticle);
	DeleteGO(ui);
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