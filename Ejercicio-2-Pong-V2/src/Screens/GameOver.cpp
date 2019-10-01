#include "GameOver.h"

#include "raylib.h"
#include "Game.h"
#include "Palette.h"


static void UpdateGameOver();
static void DrawGameOver();

void RunGameOver()
{
	UpdateGameOver();
}
static void DrawGameOver()
{
	BeginDrawing();

	ClearBackground(BLACK);
	if (player1Points == maxScore) DrawText("PLAYER 1 WINS!!", 300, 50, 20, RAYWHITE),
		DrawText("PRESS \"ENTER\" TO RETURN MENU", 210, 100, 20, RAYWHITE),
		DrawText("PRESS \"ESCAPE\" TO CLOSE GAME", 210, 150, 20, RAYWHITE);
	else if (player2Points == maxScore) DrawText("PLAYER 2 WINS!!", 300, 50, 20, RAYWHITE),
		DrawText("PRESS \"ENTER\" TO RETURN MENU", 210, 100, 20, RAYWHITE),
		DrawText("PRESS \"ESCAPE\" TO CLOSE GAME", 210, 150, 20, RAYWHITE);
	EndDrawing();
}
static void UpdateGameOver()
{
	DrawGameOver();
	if (IsKeyDown(KEY_ENTER)) playing = true, playing = !playing, menu = !menu, InitRecPositionNScore(), InitRecColor();
}