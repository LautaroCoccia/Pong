
#include "raylib.h"
#include "Palette.h"

Color colorOptions[5] = { BLUE,GOLD, RED, GREEN, PURPLE };
Vector2 rectangleZise = { (rentangleWidth), (rectangleHeight) };
Rectangle boxP1 = { rentangleWidth, (screenHeight / 2) - (rectangleHeight / 2) , rentangleWidth, rectangleHeight };
Rectangle boxP2 = { (screenWidth - (rectangleHeight / 2)), (screenHeight / 2) - (rectangleHeight / 2),
	rentangleWidth, rectangleHeight };
int player1Points = 0;
int player2Points = 0;
int countP1 = 0;
int countP2 = 1;
void InitRecColor()
{
	SetColorPlayer1();
	SetColorPlayer2();
}
void SetColorPlayer1()
{
	boxP1.color = colorOptions[countP1];
}
void SetColorPlayer2()
{
	boxP2.color = colorOptions[countP2];
}

void CheckColorPlayer1Right()
{
	if (countP1 < 4 && (countP1 + 1) != countP2)
	{
		countP1 = (countP1 + 1);
	}
	else if (countP1 < 3 && (countP1 + 1) == countP2)
	{
		countP1 = (countP1 + 2);
		
	}
	else if ((countP1 + 1) >= 3 && countP2 != 0)
	{
		countP1 = 0;
	}
	else if (((countP1 + 1) >= 3 && countP2 == 0))
	{
		countP1 = 1;
	}
	SetColorPlayer1();
}
void CheckColorPlayer1Left()
{
	if (countP1 > 0 && (countP1 - 1) != countP2)
	{
		countP1 = (countP1 - 1);
		
	}
	else if (countP1 > 1 && (countP1 - 1) == countP2)
	{
		countP1 = (countP1 - 2);
		
	}
	else if ((countP1 - 2) < 0 && countP2 != 4)
	{
		countP1 = 4;
		
	}
	else if (((countP1 - 1) < 0 && countP2 == 4))
	{
		countP1 = 3;
		
	}
	SetColorPlayer1();
}

void CheckColorPlayer2Right()
{
	if (countP2 < 4 && (countP2 + 1) != countP1)
	{
		countP2 = (countP2 + 1);
		
	}
	else if (countP2 < 3 && (countP2 + 1) == countP1)
	{
		countP2 = (countP2 + 2);
		
	}
	else if ((countP2 + 1) >= 3 && countP1 != 0)
	{
		countP2 = 0;
		
	}
	else if (((countP2 + 1) >= 3 && countP1 == 0))
	{
		countP2 = 1;
		
	}
	SetColorPlayer2();
}
void CheckColorPlayer2Left()
{
	if (countP2 > 0 && (countP2 - 1) != countP1)
	{
		countP2 = (countP2 - 1);
		
	}
	else if (countP2 > 1 && (countP2 - 1) == countP1)
	{
		countP2 = (countP2 - 2);
		
	}
	else if ((countP2 - 2) < 0 && countP1 != 4)
	{
		countP2 = 4;
		
	}
	else if (((countP2 - 1) < 0 && countP1 == 4))
	{
		countP2 = 3;
		
	}
	SetColorPlayer2();
}

void DrawRectangles()
{
	DrawRectangleRec(boxP2, boxP2.color);
	DrawRectangleRec(boxP1, boxP1.color);
}
void DrawPlayersPoints()
{
	DrawText(TextFormat("Player 1: %i", player1Points), 10, 10, 20, RAYWHITE);
	DrawText(TextFormat("Player 2: %i", player2Points), 650, 10, 20, RAYWHITE);
}
void CheckPlayerMovement()
{
	//Player 1
	//----------------------------------------------------------------------------------
	if (IsKeyDown(KEY_W) && boxP1.y > (limit)) boxP1.y -= rectangleMovement * GetFrameTime();
	if (IsKeyDown(KEY_S) && boxP1.y < (screenHeight - rectangleHeight * 2 + limit)) boxP1.y += rectangleMovement * GetFrameTime();

	//Player 2
	//----------------------------------------------------------------------------------
	if (IsKeyDown(KEY_UP) && boxP2.y > (limit)) boxP2.y -= rectangleMovement * GetFrameTime();
	if (IsKeyDown(KEY_DOWN) && boxP2.y < (screenHeight - rectangleHeight * 2 + limit)) boxP2.y += rectangleMovement* GetFrameTime();
}

void InitRecPosition()
{
	boxP1 = { rentangleWidth, (screenHeight / 2) - (rectangleHeight / 2) , rentangleWidth, rectangleHeight };
	boxP2 = { (screenWidth - (rectangleHeight / 2)), (screenHeight / 2) - (rectangleHeight / 2),
	rentangleWidth, rectangleHeight };
}