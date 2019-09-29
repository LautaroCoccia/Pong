#ifndef POWERUP_H
#define POWERUP_H
#include "raylib.h"

struct PowerUp
{
	float ballMovementY = 400.0f;
	float ballRadius = 15.0f;
	Vector2 position;
	Vector2 ballSpeed;
	Color ballColor = WHITE;
	bool active;
};
extern PowerUp largePalettePower;
extern void InitPowerUp();
extern void InitTimer();
extern void ActivatePowerUp();
extern void EnlargePaletteP1();
extern void EnlargePaletteP2();
extern void NormalizedHeight();
extern void DrawPowerUp();
#endif
