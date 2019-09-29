#include "Game.h"

#include "raylib.h"
#include "Palette.h"
#include "Ball.h"
#include "PowerUps.h"
#include "Textures.h"

bool menu = true;
bool playing = false;
static void UpdateGame();
static void CheckWin();
static void SetGameAspectRatio();
static void CheckColisionBallPlayers();
static void CheckColisionBallPowerUp();
void RunGame()
{
	UpdateGame();
	
}

static void UpdateGame()
{
	CheckPlayerMovement();
	BallObj::CheckBallWallsLimit();
	CheckColisionBallPlayers();
	CheckColisionBallPowerUp();
	ActivatePowerUp();
	NormalizedHeight();

	BeginDrawing();
	ClearBackground(BLACK);
	DrawPlayersPoints();
	DrawRectangles();
	DrawPowerUp();
	BallObj::DrawMyBall();
	EndDrawing();
	CheckWin();
}

static void CheckWin()
{
	if (player1Points == maxScore || player2Points == maxScore)playing = false;
}
static void SetGameAspectRatio()
{
	BallObj::SetBallAspectRatio();
	SetPalettesAspectRatio();
}

static void CheckColisionBallPlayers()
{

	if (CheckCollisionCircleRec(BallObj::ball.ballPosition, BallObj::ball.ballRadius, boxP1) && BallObj::checkColission == true)
	{
		BallObj::ball.ballPosition.x = (boxP1.x +boxP1.width) + BallObj::ball.ballRadius;
		BallObj::checkColission = false;
		BallObj::ball.ballColor = boxP1.color;
		BallObj::ball.ballSpeed.x *= BallObj::increaseMovementX;

	}

	if (CheckCollisionCircleRec(BallObj::ball.ballPosition, BallObj::ball.ballRadius, boxP2) && BallObj::checkColission == false)
	{
		BallObj::ball.ballSpeed.x *= BallObj::increaseMovementX;
		BallObj::checkColission = true;
		BallObj::ball.ballColor = boxP2.color;
	}
	BallObj::ball.ballPosition.x += BallObj::ball.ballSpeed.x * GetFrameTime();
	BallObj::ball.ballPosition.y += BallObj::ball.ballSpeed.y * GetFrameTime();
}
static void CheckColisionBallPowerUp()
{
	if (largePalettePower.active && CheckCollisionCircles(BallObj::ball.ballPosition, BallObj::ball.ballRadius, largePalettePower.position, largePalettePower.ballRadius))
	{
		if (BallObj::checkColission)
		{
			EnlargePaletteP2();
			NormalizedPowerUpedPalettesPosition();
		}
		else if (BallObj::checkColission == false)
		{
			EnlargePaletteP1();
			NormalizedPowerUpedPalettesPosition();
		}
		
		InitPalettesTextures();
		void InitTimer();
		largePalettePower.active = false;

	};
}

