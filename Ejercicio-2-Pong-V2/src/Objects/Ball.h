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
	extern Ball ball;
	extern  bool checkColission;
	extern const float increaseMovementX;
	void InitBall();
	void CheckBallWallsLimit();
	void DrawMyBall();
	void SetBallAspectRatio();
}
#endif // !BALL_H

