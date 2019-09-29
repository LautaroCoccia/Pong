
#include "raylib.h"
#include "Palette.h"
enum Colors 
{
	color0 = 0,
	color1,
	color2,
	color3,
	color4,
};
Color colorOptions[5] = { BLUE,GOLD, RED, GREEN, PURPLE };
Vector2 rectangleZise = { (rentangleWidth), (rectangleHeight) };
Rectangle boxP1 = { rentangleWidth, halfScreenHeight - halfRectangleHeight , rentangleWidth, rectangleHeight };
Rectangle boxP2 = { (screenWidth - halfRectangleHeight ), (halfScreenHeight  - halfRectangleHeight) ,
	rentangleWidth, rectangleHeight };
int player1Points = 0;
int player2Points = 0;
int colorP1 = color0;
int colorP2 = color1; 

void SetColorPlayer1();
void SetColorPlayer2();

void InitRecColor()
{
	SetColorPlayer1();
	SetColorPlayer2();
}
void SetColorPlayer1()
{
	boxP1.color = colorOptions[colorP1];
}
void SetColorPlayer2()
{
	boxP2.color = colorOptions[colorP2];
}

void CheckColorPlayer1Right()
{
	if (colorP1 < color4 && (colorP1 + 1) != colorP2)
	{
		colorP1 = (colorP1 + 1);
	}
	else if (colorP1 < color3 && (colorP1 + 1) == colorP2)
	{
		colorP1 = (colorP1 + 2);
		
	}
	else if ((colorP1 + 1) >= color3 && colorP2 != color0)
	{
		colorP1 = color0;
	}
	else if (((colorP1 + 1) >= color3 && colorP2 == color0))
	{
		colorP1 = color1;
	}
	SetColorPlayer1();
}
void CheckColorPlayer1Left()
{
	if (colorP1 > color0 && (colorP1 - 1) != colorP2)
	{
		colorP1 = (colorP1 - 1);
		
	}
	else if (colorP1 > color1 && (colorP1 - 1) == colorP2)
	{
		colorP1 = (colorP1 - 2);
		
	}
	else if ((colorP1 - 2) < 0 && colorP2 != color4)
	{
		colorP1 = color4;
		
	}
	else if (((colorP1 - 1) < color0 && colorP2 == color4))
	{
		colorP1 = color3;
		
	}
	SetColorPlayer1();
}

void CheckColorPlayer2Right()
{
	if (colorP2 < color4 && (colorP2 + 1) != colorP1)
	{
		colorP2 = (colorP2 + 1);
		
	}
	else if (colorP2 < color3 && (colorP2 + 1) == colorP1)
	{
		colorP2 = (colorP2 + 2);
		
	}
	else if ((colorP2 + 1) >= color3 && colorP1 != color0)
	{
		colorP2 = color0;
		
	}
	else if (((colorP2 + 1) >= 3 && colorP1 == 0))
	{
		colorP2 = color1;
		
	}
	SetColorPlayer2();
}
void CheckColorPlayer2Left()
{
	if (colorP2 > color0 && (colorP2 - 1) != colorP1)
	{
		colorP2 = (colorP2 - 1);
		
	}
	else if (colorP2 > 1 && (colorP2 - 1) == colorP1)
	{
		colorP2 = (colorP2 - 2);
		
	}
	else if ((colorP2 - 2) < 0 && colorP1 != 4)
	{
		colorP2 = color4;
		
	}
	else if (((colorP2 - 1) < color0 && colorP1 == color4))
	{
		colorP2 = color3;
		
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
	if (IsKeyDown(KEY_S) && boxP1.y < (screenHeight - rectangleHeight )) boxP1.y += rectangleMovement * GetFrameTime();

	//Player 2
	//----------------------------------------------------------------------------------
	if (IsKeyDown(KEY_UP) && boxP2.y > (limit)) boxP2.y -= rectangleMovement * GetFrameTime();
	if (IsKeyDown(KEY_DOWN) && boxP2.y < (screenHeight - rectangleHeight )) boxP2.y += rectangleMovement* GetFrameTime();
}

void InitRecPosition()
{
	boxP1 = { rentangleWidth, (halfScreenHeight  - halfRectangleHeight) , rentangleWidth, rectangleHeight };
	boxP2 = { (screenWidth - halfRectangleHeight ), (halfScreenHeight - halfRectangleHeight ),
	rentangleWidth, rectangleHeight };
}