/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
struct Ball{
	float ballMovementX;
	float ballMovementY;
	int ballSize;
	Vector2 ballPosition;
	Vector2 ballSpeed;
	Color ballColor;
	bool ballDirection;

};
struct Ball ball;
enum GameState 
{
	play,
	menu,
	exit,
};
enum GameState gameState;
int main(void) {

	// Initialization
	//---------------------------------------------------------------------------------------

	const int screenWidth = 800;
	const int screenHeight = 450;
	ball.ballMovementX = 7.0f;
	ball.ballMovementY = 5.0f;
	ball.ballColor = WHITE;
	ball.ballPosition.x = (float)screenWidth / 2;
	ball.ballPosition.y = (float)screenHeight / 2;
	ball.ballSize = 10.0f;
	ball.ballDirection = false;
	ball.ballSpeed.x = ball.ballMovementX;
	ball.ballSpeed.y = ball.ballMovementY;
	const int limit = 35;
	const float rectangleMovement = 6.0f;
	const int rectangleHeight = 80;
	const int rentangleWidth = 10;
	int player1Points = 0;
	int player2Points = 0;
	Color colorOptions[5] = { BLUE,GOLD, RED, GREEN, PURPLE };
	bool checkColission = false;

	InitWindow(screenWidth, screenHeight, "PONG.exe - Lautaro Coccia");

	Vector2 rectangleZise = { (int)(rentangleWidth), (int)(rectangleHeight) };
	Rectangle boxP1 = { (float)(rectangleHeight / 2), (float)(screenHeight / 2) - (rectangleHeight / 2) , rentangleWidth, rectangleHeight };
	Rectangle boxP2 = { (float)(screenWidth - (rectangleHeight / 2)), (float)(screenHeight / 2) - (rectangleHeight / 2),
		rentangleWidth, rectangleHeight };

	

	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);     
	//Game Menu loop
	bool game = true;
	bool playing = true;
	int countP1 = 0;
	int countP2 = 1;
	boxP1.color = colorOptions[countP1];
	boxP2.color = colorOptions[countP2];
	// Main game loop
	while (game) {   
		
		do {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("PONG", 360, 50, 20, RAYWHITE);
			DrawText("PRESS ENTER", 310, 125, 20, RAYWHITE);
			DrawText("SELECT BAR COLOR", 285, 100, 20, RAYWHITE);
			if (IsKeyPressed(KEY_D)) {
				if (countP1 < 4) {
					countP1 = (countP1 + 1);
					boxP1.color = colorOptions[countP1];
				}
				else {
					countP1 = 0;
					boxP1.color = colorOptions[countP1];
				}
			}
			if (IsKeyPressed(KEY_A)) {
				if (countP1 > 0) {
					countP1 = (countP1 - 1);
					boxP1.color = colorOptions[countP1];
				}
				else {
					countP1 = 4;
					boxP1.color = colorOptions[countP1];
				}
			}
			if (IsKeyPressed(KEY_RIGHT)) {
				if (countP2 < 4) {
					countP2 = (countP2 + 1);
					if ((countP2 + 1) == countP1)
					{
						countP2 = (countP2 + 2);
						if (countP2 > 4) {
							countP2 = 0;
						}
						boxP2.color = colorOptions[countP2];
					}
					else
					{
						countP2 = (countP2 + 1);
						boxP2.color = colorOptions[countP2];
					}
				}
				else {
					countP2 = 0;
					boxP2.color = colorOptions[countP2];
				}
			}
			if (IsKeyPressed(KEY_LEFT)) {
				if (countP2 > 0) {
					if ((countP2 - 1) == countP1)
					{
						countP2 = (countP2 - 2);
						if (countP2 < 0) {
							countP2 = 4;
						}
						
						boxP2.color = colorOptions[countP2];
					}
					else
					{
						countP2 = (countP2 - 1);
						boxP2.color = colorOptions[countP2];
					}
					
				}
				else {
					countP2 = 4;
					boxP2.color = colorOptions[countP2];
				}
			}
			DrawRectangleRec(boxP2, boxP2.color);
			DrawRectangleRec(boxP1, boxP1.color);
			EndDrawing();
		} while (IsKeyUp(KEY_ENTER));
		if (IsKeyPressed(KEY_ENTER)) {

			while (playing) {
				// Update
		        //----------------------------------------------------------------------------------
				//Player 1
				//----------------------------------------------------------------------------------
				if (IsKeyDown(KEY_W) && boxP1.y > (limit)) boxP1.y -= rectangleMovement;
				if (IsKeyDown(KEY_S) && boxP1.y < (screenHeight - rectangleHeight)) boxP1.y += rectangleMovement;

				//Player 2
				//----------------------------------------------------------------------------------
				if (IsKeyDown(KEY_UP) && boxP2.y > (limit)) boxP2.y -= rectangleMovement;
				if (IsKeyDown(KEY_DOWN) && boxP2.y < (screenHeight - rectangleHeight)) boxP2.y += rectangleMovement;

				// Check walls limit
				//----------------------------------------------------------------------------------
				if ((ball.ballPosition.x >= (GetScreenWidth() - ball.ballSize))) ball.ballPosition.x = (float)screenWidth / 2, (float)screenHeight / 2,
					player1Points++, ball.ballColor = WHITE;
				else if (ball.ballPosition.x <= ball.ballSize)
					ball.ballPosition.x = (float)screenWidth / 2, (float)screenHeight / 2, player2Points++, ball.ballColor = WHITE;
				if ((ball.ballPosition.y >= (GetScreenHeight() - ball.ballSize)) || (ball.ballPosition.y <= (ball.ballSize + limit))) ball.ballSpeed.y *= -1.0f;

				if (player1Points == 3 || player2Points == 3) game = false;
				// collision
				//----------------------------------------------------------------------------------
				if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize, boxP1) && checkColission == true) ball.ballDirection = false, ball.ballSpeed.x *= -1.0f,
					checkColission = false, ball.ballColor = boxP1.color;
				if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize, boxP2) && checkColission == false) ball.ballDirection = true, ball.ballSpeed.x *= -1.0f,
					checkColission = true, ball.ballColor = boxP2.color;

				ball.ballPosition.x += ball.ballSpeed.x;
				ball.ballPosition.y += ball.ballSpeed.y;
				if (player1Points == 3 || player2Points == 3)playing = false;
				// Draw
				//----------------------------------------------------------------------------------
				BeginDrawing();

				ClearBackground(BLACK);

				DrawText(TextFormat("Player 1: %i", player1Points), 10, 10, 20, RAYWHITE);
				DrawText(TextFormat("Player 2: %i", player2Points), 650, 10, 20, RAYWHITE);
				DrawRectangleRec(boxP2, boxP2.color);
				DrawRectangleRec(boxP1, boxP1.color);
				DrawCircleV(ball.ballPosition, ball.ballSize, ball.ballColor);
				EndDrawing();
				//----------------------------------------------------------------------------------
				while (!playing) {
					BeginDrawing();

					ClearBackground(BLACK);
					if (player1Points == 3) DrawText("PLAYER 1 WINS!!", 300, 50, 20, RAYWHITE),
						DrawText("PRESS \"F\" TO PAY RESPECTS AND PLAY AGAIN", 175, 100, 20, RAYWHITE);
					else if (player2Points == 3) DrawText("PLAYER 2 WINS!!", 300, 50, 20, RAYWHITE),
						DrawText("PRESS \"F\" TO PAY RESPECTS AND PLAY AGAIN", 175, 100, 20, RAYWHITE);
					EndDrawing();
					if (IsKeyDown(KEY_F)) playing = true, player1Points = 0, player2Points = 0;
					// De-Initialization
					//--------------------------------------------------------------------------------------
					else if (IsKeyDown(KEY_ESCAPE))  CloseWindow(); // Close window and OpenGL context
					//--------------------------------------------------------------------------------------
				};
			}
		
		}
		
		
	};
	
	return 0;
}
