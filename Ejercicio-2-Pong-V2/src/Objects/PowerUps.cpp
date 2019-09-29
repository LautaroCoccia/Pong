#include "PowerUps.h"

#include <ctime>

#include "Textures.h"
#include "Palette.h"
#include "Ball.h"


PowerUp largePalettePower;
PowerUp littleBall;
const float reducideBallRadius = BallObj::ball.ballRadius / 2;
const int largePaletteHeight = commonRectangleHeight + halfRectangleHeight;
const float timerInit = 0;
const float maxTime = 5;
const float initialPosX = 400;
const float initialPosY = 150;
float timeToActive = timerInit;

void InitPowerUp()
{
	InitTimer();
	largePalettePower.active = false;
	largePalettePower.position.x = initialPosX;
	largePalettePower.position.y = initialPosY;
}
void EnlargePaletteP1()
{
	boxP1.height = largePaletteHeight;
}
void EnlargePaletteP2()
{
	boxP2.height = largePaletteHeight;
}

void NormalizedHeight()
{
	if (largePalettePower.active)
	{
		boxP1.height = commonRectangleHeight;
		boxP2.height = commonRectangleHeight;
		InitPalettesTextures();
	}
}

void DrawPowerUp()
{
	if (largePalettePower.active == true)
	{
		DrawCircle(static_cast<int>(largePalettePower.position.x), static_cast<int>(largePalettePower.position.y), largePalettePower.ballRadius, largePalettePower.ballColor);
	}
}
void ActivatePowerUp()
{
	if (largePalettePower.active == false)
	{
		timeToActive += GetFrameTime();
		if (timeToActive >= maxTime)
		{
			largePalettePower.active = true;
			InitTimer();
		}
	}
}
void InitTimer()
{
	timeToActive = timerInit;
}