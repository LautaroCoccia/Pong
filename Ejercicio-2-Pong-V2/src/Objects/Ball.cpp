#include "Ball.h"
#include "Palette.h"
#include "raylib.h"
//Texture2D LoadImage("Ball.png");

 Ball ball;
 bool checkColission = false;
 const float ballMovementY = 375.0f;
 const float ballMovementX = 500.0f;
 const float changeDirectionY = -1.0f;
 const float increaseMovementX = -1.05f;
 const float multiplyAngle = 250;
void InitBall()
{
	ball.ballPosition= { halfScreenWidth,  halfScreenHeight };
	ball.ballSpeed = { ball.ballMovementX, ball.ballMovementY };
}

void CheckBallWallsLimit()
{
	// Check ball-walls limit
	//----------------------------------------------------------------------------------
	if ((ball.ballPosition.x >= (GetScreenWidth() - ball.ballSize))) ball.ballPosition.x = halfScreenWidth, halfScreenHeight,
		player1Points++, ball.ballColor = WHITE, ball.ballSpeed.x = ballMovementX, ball.ballSpeed.y = ballMovementY;
	else if (ball.ballPosition.x <= ball.ballSize)
		ball.ballPosition.x = halfScreenWidth, halfScreenHeight, player2Points++, ball.ballColor = WHITE, ball.ballSpeed.x = ballMovementX * changeDirectionY;
			
	if ((ball.ballPosition.y >= (GetScreenHeight() - ball.ballSize)))
		ball.ballPosition.y = (GetScreenHeight() - ball.ballSize),ball.ballSpeed.y *= changeDirectionY;
	else if (ball.ballPosition.y <= (ball.ballSize + limit))
		ball.ballSpeed.y *= changeDirectionY;

}
void CheckColisionWithPlayers()
{
	
	if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize, boxP1) && checkColission == true)
	{
		checkColission = false;
		ball.ballColor = boxP1.color;
		ball.ballSpeed.x *= increaseMovementX ;
		/*if (boxP1.y < halfScreenHeight - halfRectangleHeight)
		{
			ball.ballSpeed.y = (ball.ballPosition.y - boxP1.y) / halfRectangleHeight * 100;
		}
		else
		{
			ball.ballSpeed.y = (ball.ballPosition.y - boxP1.y) / halfRectangleHeight * multiplyAngle;
		}*/
		
			
	}
       
	if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize, boxP2) && checkColission == false)
	{
		ball.ballSpeed.x *= increaseMovementX;
		checkColission = true;
		ball.ballColor = boxP2.color;
	/*	if (boxP2.y < halfScreenHeight + halfRectangleHeight)
		{
			
			ball.ballSpeed.y = (ball.ballPosition.y - boxP2.y) / halfRectangleHeight * 100;
		}
		else
		{
			ball.ballSpeed.y = (ball.ballPosition.y - boxP2.y) / rectangleHeight * multiplyAngle;
		}*/
		
			
	}
	ball.ballPosition.x += ball.ballSpeed.x * GetFrameTime();
	ball.ballPosition.y += ball.ballSpeed.y * GetFrameTime();
}
void DrawMyBall()
{
	DrawCircleV(ball.ballPosition, ball.ballSize, ball.ballColor);
}
