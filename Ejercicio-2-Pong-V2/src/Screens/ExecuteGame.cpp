#include "raylib.h"
#include "ExecuteGame.h"
#include "Menu.h"
#include "Textures.h"
#include "Palette.h"
#include "Game.h"
#include "Ball.h"
#include "PowerUps.h"
#include "GameOver.h"

void ExecuteGame()
{
	// Initialization
	//---------------------------------------------------------------------------------------
	InitWindow(BaseScreenWidth, BaseScreenHeight, "PONG.exe - Lautaro Coccia");
	
	 
	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);

	// Main game loop
	//--------------------------------------------------------------------------------------
	InitRecColor();
	loadPalettesTextures();
	BallObj::InitBall();
	InitPowerUp();

	while (!WindowShouldClose() || IsKeyDown(KEY_ESCAPE))
	{
		if (menu)
		{
			RunMenu();
		}
		else if (playing)
		{
			RunGame();
		}
		else if (!playing)
		{
			RunGameOver();
		}

	}
	CloseWindow();
	
}