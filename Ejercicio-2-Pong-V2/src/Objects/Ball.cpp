#include "Ball.h"
#include "Palette.h"
#include "Textures.h"

namespace BallObj
{
	Ball ball;
	Sound colisionSound;
	bool checkColission = false;
	const float ballMovementY = 375.0f;
	const float ballMovementX = 500.0f;
	const float changeDirectionY = -1.0f;
	const float increaseMovementX = -1.03f;

	
	void InitBall()
	{
		LoadBallTexture();
		ball.ballPosition = { halfScreenWidth,  halfScreenHeight };
		ball.ballSpeed = { ball.ballMovementX, ball.ballMovementY };
	}
	void LoadColisionSound()
	{
		colisionSound = LoadSound("sounds/ColisionSound.wav");
	}
	void UnloadMySound()
	{
		UnloadSound(colisionSound);
	}
	void CheckBallWallsLimit()
	{
		// Check ball-walls limit
		//----------------------------------------------------------------------------------
		if ((ball.ballPosition.x >= (GetScreenWidth() - ball.ballRadius)))
		{
			ball.ballPosition.x = halfScreenWidth, ball.ballPosition.y = halfScreenHeight, player1Points++, ball.ballColor = WHITE,
				ball.ballSpeed.x = ballMovementX, ball.ballSpeed.y = ballMovementY;
		}
		if (ball.ballPosition.x <= ball.ballRadius - ball.ballRadius)
		{
			ball.ballPosition.x = halfScreenWidth, ball.ballPosition.y = halfScreenHeight, player2Points++, ball.ballColor = WHITE,
				ball.ballSpeed.x = ballMovementX * changeDirectionY;
		}
			
		if ((ball.ballPosition.y >= (GetScreenHeight() - ball.ballRadius)))
		{
			ball.ballPosition.y = (GetScreenHeight() - ball.ballRadius), ball.ballSpeed.y *= changeDirectionY;
		}
			
		if (ball.ballPosition.y <= (ball.ballRadius + limit))
		{
			ball.ballPosition.y = (ball.ballRadius + limit), ball.ballSpeed.y *= changeDirectionY;
		}
			
	}
	
	void DrawMyBall()
	{
		DrawBallTexture();
	}
	void SetBallAspectRatio()
	{
		ball.ballPosition.x = ball.ballPosition.x * GetScreenWidth() / BaseScreenWidth;
		ball.ballPosition.y = ball.ballPosition.y * GetScreenHeight() / BaseScreenHeight;
		ball.ballRadius = ball.ballRadius * GetScreenWidth() / BaseScreenWidth;
		ball.ballMovementX = ball.ballMovementX * GetScreenWidth() / BaseScreenWidth;
		ball.ballMovementY = ball.ballMovementY * GetScreenWidth() / BaseScreenWidth;
	}
}
	

	
