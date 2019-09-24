
#include "raylib.h"
#include "Menu.h"
#include "Palette.h"
#include "Game.h"
#include "Ball.h"
#include "GameOver.h"
#include "ExecuteGame.h"
void ExecuteGame()
{
	// Initialization
	//---------------------------------------------------------------------------------------
	InitWindow(800, 450, "PONG.exe - Lautaro Coccia");
	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);

	// Main game loop
	InitRecColor();
	InitBall();
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
		};


	}
	CloseWindow();
	
}