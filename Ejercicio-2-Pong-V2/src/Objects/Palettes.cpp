#include "Palette.h"
#include "Textures.h"
float rectangleMovement = 550.0f;
const int maxColors = 5;
const int initScore = 0;
enum Colors 
{
	color0 = 0,
	color1,
	color2,
	color3,
	color4
};
enum Seleccion
{
	selection0 = 0,
	selection1,
	selection2,
	selection3,
	selection4
};
Color colorOptions[maxColors] = { BLUE,GOLD, RED, GREEN, PURPLE };
Vector2 rectangleZise = { (rentangleWidth), (commonRectangleHeight) };
Rectangle boxP1 = { rentangleWidth, halfScreenHeight - halfRectangleHeight , rentangleWidth, commonRectangleHeight };
Rectangle boxP2 = { (BaseScreenWidth - halfRectangleHeight ), (halfScreenHeight  - halfRectangleHeight) ,
	rentangleWidth, commonRectangleHeight };
int player1Points = initScore;
int player2Points = initScore;
int colorP1 = color0;
int colorP2 = color1; 

static void SetColorPlayer1();
static void SetColorPlayer2();

void InitRecColor()
{
	SetColorPlayer1();
	SetColorPlayer2();
}
static void SetColorPlayer1()
{
	boxP1.color = colorOptions[colorP1];
}

static void SetColorPlayer2()
{
	boxP2.color = colorOptions[colorP2];
}

void CheckColorPlayer1Right()
{
	if (colorP1 < color4 && (colorP1 + selection1) != colorP2)
	{
		colorP1 = (colorP1 + selection1);
	}
	else if (colorP1 < color3 && (colorP1 + selection1) == colorP2)
	{
		colorP1 = (colorP1 + selection2);
		
	}
	else if ((colorP1 + selection1) >= color3 && colorP2 != color0)
	{
		colorP1 = color0;
	}
	else if (((colorP1 + selection1) >= color3 && colorP2 == color0))
	{
		colorP1 = color1;
	}
	SetColorPlayer1();
}

void CheckColorPlayer1Left()
{
	if (colorP1 > color0 && (colorP1 - selection1) != colorP2)
	{
		colorP1 = (colorP1 - selection1);
		
	}
	else if (colorP1 > color1 && (colorP1 - selection1) == colorP2)
	{
		colorP1 = (colorP1 - selection2);
		
	}
	else if ((colorP1 - selection2) < selection0 && colorP2 != color4)
	{
		colorP1 = color4;
		
	}
	else if (((colorP1 - selection1) < color0 && colorP2 == color4))
	{
		colorP1 = color3;
		
	}
	SetColorPlayer1();
}

void CheckColorPlayer2Right()
{
	if (colorP2 < color4 && (colorP2 + selection1) != colorP1)
	{
		colorP2 = (colorP2 + selection1);
		
	}
	else if (colorP2 < color3 && (colorP2 + selection1) == colorP1)
	{
		colorP2 = (colorP2 + selection2);
		
	}
	else if ((colorP2 + selection1) >= color3 && colorP1 != color0)
	{
		colorP2 = color0;
		
	}
	else if (((colorP2 + selection1) >= selection2 && colorP1 == selection0))
	{
		colorP2 = color1;
		
	}
	SetColorPlayer2();
}

void CheckColorPlayer2Left()
{
	if (colorP2 > color0 && (colorP2 - selection1) != colorP1)
	{
		colorP2 = (colorP2 - selection1);
		
	}
	else if (colorP2 > selection1 && (colorP2 - selection1) == colorP1)
	{
		colorP2 = (colorP2 - selection2);
		
	}
	else if ((colorP2 - selection2) < selection0 && colorP1 != selection4)
	{
		colorP2 = color4;
		
	}
	else if (((colorP2 - selection1) < color0 && colorP1 == color4))
	{
		colorP2 = color3;
		
	}
	SetColorPlayer2();
}

void CheckPlayerMovement()
{
	//Player 1
	//----------------------------------------------------------------------------------
	if (IsKeyDown(KEY_W) && boxP1.y > (limit)) boxP1.y -= rectangleMovement * GetFrameTime();
	if (IsKeyDown(KEY_S) && boxP1.y < (BaseScreenHeight - boxP1.height)) boxP1.y += rectangleMovement * GetFrameTime();

	//Player 2
	//----------------------------------------------------------------------------------
	if (IsKeyDown(KEY_UP) && boxP2.y > (limit)) boxP2.y -= rectangleMovement * GetFrameTime();
	if (IsKeyDown(KEY_DOWN) && boxP2.y < (BaseScreenHeight - boxP2.height)) boxP2.y += rectangleMovement * GetFrameTime();
}

void InitRecPositionNScore()
{
	player1Points = initScore;
	player2Points = initScore;
	boxP1 = { rentangleWidth, (halfScreenHeight - halfRectangleHeight) , rentangleWidth, commonRectangleHeight };
	boxP2 = { (BaseScreenWidth - halfRectangleHeight), (halfScreenHeight - halfRectangleHeight),
	rentangleWidth, commonRectangleHeight };
}

void SetPalettesAspectRatio()
{
	boxP1.x = boxP1.x * GetScreenWidth() / BaseScreenWidth;
	boxP1.width = boxP1.width* GetScreenWidth() / BaseScreenWidth;
	boxP1.y = boxP1.y * GetScreenWidth() / BaseScreenHeight;
	boxP1.height = boxP1.height * GetScreenWidth() / BaseScreenHeight;

	boxP2.x = boxP2.x * GetScreenWidth() / BaseScreenWidth;
	boxP2.width = boxP2.width * GetScreenWidth() / BaseScreenWidth;
	boxP2.y = boxP2.y * GetScreenWidth() / BaseScreenHeight;
	boxP2.height = boxP2.height * GetScreenWidth() / BaseScreenHeight;

	rectangleMovement = rectangleMovement * GetScreenWidth() / BaseScreenHeight;
}

void DrawRectangles()
{
	DrawPalettesTextures();
}
void NormalizedPowerUpedPalettesPosition()
{
	if (boxP1.y > (BaseScreenHeight - boxP1.height))
	{
		boxP1.y = BaseScreenHeight - boxP1.height;
	}
	if (boxP2.y > (BaseScreenHeight - boxP2.height))
	{
		boxP2.y = BaseScreenHeight - boxP2.height;
	}
}
void DrawPlayersPoints()
{
	DrawText(TextFormat("Player 1: %i", player1Points), 10, 10, 20, RAYWHITE);
	DrawText(TextFormat("Player 2: %i", player2Points), 650, 10, 20, RAYWHITE);
}

