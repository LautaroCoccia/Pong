#include "Ball.h"
#include "Palette.h"
#include "raylib.h"

 Ball ball;
 bool checkColission = false;
void InitBall()
{
	ball.ballPosition= { static_cast<float> (800 / 2),  static_cast<float>(450 / 2) };
	ball.ballSpeed = { ball.ballMovementX, ball.ballMovementY };
}

void CheckBallWallsLimit()
{
	// Check ball-walls limit
	//----------------------------------------------------------------------------------
	if ((ball.ballPosition.x >= (GetScreenWidth() - ball.ballSize))) ball.ballPosition.x = static_cast<float>(screenWidth / 2), static_cast<float>(screenHeight / 2),
		player1Points++, ball.ballColor = WHITE,ball.ballSpeed.x = 500.0f,ball.ballSpeed.y = 400.0f;
	else if (ball.ballPosition.x <= ball.ballSize)
			ball.ballPosition.x = static_cast<float>(screenWidth / 2), static_cast<float>(screenHeight / 2), player2Points++, ball.ballColor = WHITE,ball.ballSpeed.x = 500.0f*-1,
			ball.ballSpeed.y = 400.0f *-1;
	if ((ball.ballPosition.y >= (GetScreenHeight() - ball.ballSize)) || (ball.ballPosition.y <= (ball.ballSize + limit))) ball.ballSpeed.y *= -1.0f ;

}
void CheckColisionWithPlayers()
{
	
	if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize, boxP1) && checkColission == true)
	{
		ball.ballSpeed.x *= -1.05f ;
		ball.ballSpeed.y = (ball.ballPosition.y - boxP1.y) / (boxP1.height / 2) * 250;
		checkColission = false;
		ball.ballColor = boxP1.color;
	}
       
	if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize, boxP2) && checkColission == false)
	{
		ball.ballSpeed.x *= -1.05f ;
		ball.ballSpeed.y = (ball.ballPosition.y - boxP2.y) / (boxP2.height / 2) * 250;
		checkColission = true;
		ball.ballColor = boxP2.color;
	}
	ball.ballPosition.x += ball.ballSpeed.x * GetFrameTime();
	ball.ballPosition.y += ball.ballSpeed.y * GetFrameTime();
}
void DrawMyBall()
{
	DrawCircleV(ball.ballPosition, ball.ballSize, ball.ballColor);
}
