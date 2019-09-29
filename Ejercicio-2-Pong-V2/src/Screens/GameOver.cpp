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
		DrawText("PRESS \"F\" TO PAY RESPECTS AND PLAY AGAIN", 175, 100, 20, RAYWHITE);
	else if (player2Points == 3) DrawText("PLAYER 2 WINS!!", 300, 50, 20, RAYWHITE),
		DrawText("PRESS \"F\" TO PAY RESPECTS AND PLAY AGAIN", 175, 100, 20, RAYWHITE);
	EndDrawing();
}
static void UpdateGameOver()
{
	DrawGameOver();
	if (IsKeyDown(KEY_F)) playing = true, playing = !playing, menu = !menu, InitRecPositionNScore(), InitRecColor();
}