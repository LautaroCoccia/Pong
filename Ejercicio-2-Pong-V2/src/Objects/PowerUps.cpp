#include "PowerUps.h"

#include <ctime>

#include "Textures.h"
#include "Palette.h"
#include "Ball.h"

PowerUp largePalettePower;
PowerUp littleBall;
const float lessBallRadius = BallObj::ball.ballRadius / 2;
const int largePaletteHeight = commonRectangleHeight + halfRectangleHeight;
const float timerInit = 0;
const float maxTimeLargePalette = 5;
const float initialPosX = 400;
const float initialPosY = 150;
float timeToActive = timerInit;

void InitPowerUp()
{
	InitTimer();
	largePalettePower.active = false;
	largePalettePower.position.x = initialPosX;
	largePalettePower.position.y = initialPosY;
	littleBall.active = false;
	littleBall.position.x = initialPosX;
	littleBall.position.y = initialPosY + initialPosY;
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
void ReduceBallRadius()
{
	BallObj::ball.ballRadius = lessBallRadius;
	InitBallTextures();
}
void NormalizeBallRadius()
{
	if (littleBall.active)
	{
		BallObj::ball.ballRadius = BallObj::ball.commonBallRadius;
		InitBallTextures();
	}
}
void DrawPowerUp()
{
	if (largePalettePower.active == true)
	{
		DrawCircle(static_cast<int>(largePalettePower.position.x), static_cast<int>(largePalettePower.position.y), largePalettePower.ballRadius, largePalettePower.ballColor);
		
	}
	if (littleBall.active)
	{
		DrawCircle(static_cast<int>(littleBall.position.x), static_cast<int>(littleBall.position.y), littleBall.ballRadius, littleBall.ballColor);
	}
}
void ActivatePowerUp()
{
	if (largePalettePower.active == false)
	{ 
		timeToActive += GetFrameTime();
		if (timeToActive >= maxTimeLargePalette)
		{
			largePalettePower.active = true;
			InitTimer();
		}
	}
	if (littleBall.active == false)
	{
		timeToActive += GetFrameTime();
		if (timeToActive >= maxTimeLargePalette)
		{
			littleBall.active = true;
			InitTimer();
		}
	}
}
void InitTimer()
{
	timeToActive = timerInit;
}