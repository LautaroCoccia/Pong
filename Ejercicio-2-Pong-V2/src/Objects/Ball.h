#ifndef BALL_H
#define BALL_H
#include "raylib.h"

namespace BallObj
{
	struct Ball
	{
		float ballMovementX = 500.0f;
		float ballMovementY = 400.0f;
		const float commonBallRadius =16;
		float ballRadius = commonBallRadius;
		Vector2 ballPosition;
		Vector2 ballSpeed;
		Color ballColor = WHITE;
		bool ballDirection;
	};
	extern Sound colisionSound;
	extern Ball ball;
	extern  bool checkColission;
	extern const float increaseMovementX;
	extern void UnloadMySound();
	extern void InitBall();
	extern void LoadColisionSound();
	extern void CheckBallWallsLimit();
	extern void DrawMyBall();
	extern void SetBallAspectRatio();

}
#endif // !BALL_H

