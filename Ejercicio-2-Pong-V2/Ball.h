#ifndef BALL_H
#define BALL_H
#include "raylib.h"

struct Ball {
	float ballMovementX = 500.0f;
	float ballMovementY = 400.0f;
	int ballSize = 15.0f;
	Vector2 ballPosition;
	Vector2 ballSpeed;
	Color ballColor = WHITE;
	bool ballDirection;

};

extern Ball ball;
extern  bool checkColission;
void InitBall();
void CheckBallWallsLimit();
void CheckColisionWithPlayers();
void DrawMyBall();
#endif // !BALL_H

