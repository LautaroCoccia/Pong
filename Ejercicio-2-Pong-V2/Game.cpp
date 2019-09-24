#include "Game.h"
#include "Palette.h"
#include "raylib.h"
#include "Ball.h"

bool menu = true;
bool playing = false;
void UpdateGame();
void CheckWin();
void RunGame()
{
	UpdateGame();
}
void CheckWin()
{
	if (player1Points == 3 || player2Points == 3)playing = false;
}
void UpdateGame()
{
	CheckPlayerMovement();
	CheckBallWallsLimit();
	CheckColisionWithPlayers();
	BeginDrawing();
	ClearBackground(BLACK);
	DrawPlayersPoints();
	DrawRectangles();
	DrawMyBall();
	EndDrawing();
	CheckWin();
}