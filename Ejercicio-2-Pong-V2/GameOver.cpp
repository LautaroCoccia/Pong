#include "raylib.h"
#include "Palette.h"
#include "Game.h"
#include "GameOver.h"
void UpdateGameOver();
void DrawGameOver();

void RunGameOver()
{
	UpdateGameOver();
}
static void DrawGameOver()
{
	BeginDrawing();

	ClearBackground(BLACK);
	if (player1Points == 3) DrawText("PLAYER 1 WINS!!", 300, 50, 20, RAYWHITE),
		DrawText("PRESS \"F\" TO PAY RESPECTS AND PLAY AGAIN", 175, 100, 20, RAYWHITE);
	else if (player2Points == 3) DrawText("PLAYER 2 WINS!!", 300, 50, 20, RAYWHITE),
		DrawText("PRESS \"F\" TO PAY RESPECTS AND PLAY AGAIN", 175, 100, 20, RAYWHITE);
	EndDrawing();
}
void UpdateGameOver()
{
	DrawGameOver();
	if (IsKeyDown(KEY_F)) playing = true, player1Points = 0, player2Points = 0, playing = !playing, menu = !menu, InitRecPosition(), InitRecColor();
}