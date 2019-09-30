#include "Textures.h"
#include "Palette.h"
#include "Ball.h"

static Texture2D ballTexture;
static Texture2D rightPalette;
static Texture2D leftPalette;
void loadPalettesTextures()
{
	rightPalette = LoadTexture("RightPalette.png");
	leftPalette = LoadTexture("LeftPalette.png");
	InitPalettesTextures();
}
void DrawPalettesTextures()
{
	DrawTexture(rightPalette, static_cast<int>(boxP1.x), static_cast<int>(boxP1.y), boxP1.color);
	DrawTexture(leftPalette, static_cast<int>(boxP2.x), static_cast<int>(boxP2.y), boxP2.color);
}
void LoadBallTexture()
{
	ballTexture = LoadTexture("BALL.png");
	InitBallTextures();
}
void DrawBallTexture()
{
	DrawTexture(ballTexture, static_cast<int>(BallObj::ball.ballPosition.x - BallObj::ball.ballRadius) ,
		static_cast<int>(BallObj::ball.ballPosition.y - BallObj::ball.ballRadius), BallObj::ball.ballColor);
}
void UnloadMyTextures()
{
	UnloadTexture(ballTexture);
	UnloadTexture(leftPalette);
	UnloadTexture(rightPalette);
}

 void InitBallTextures()
{
	ballTexture.width = static_cast<int>(BallObj::ball.ballRadius + BallObj::ball.ballRadius);
	ballTexture.height = static_cast<int>(BallObj::ball.ballRadius + BallObj::ball.ballRadius);
}
void InitPalettesTextures()
{
	rightPalette.width = static_cast<int>(boxP1.width);
	rightPalette.height = static_cast<int>(boxP1.height);
	leftPalette.width = static_cast<int>(boxP2.width);
	leftPalette.height = static_cast<int>(boxP2.height);
}
