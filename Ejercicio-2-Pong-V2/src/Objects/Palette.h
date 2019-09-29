#ifndef PALETTE_H
#define PALETTE_H
#include "raylib.h"

const int rectangleHeight = 90;
const int rentangleWidth = 20;
const int halfRectangleHeight = rectangleHeight / 2;
const int halfRectangleWidth = rentangleWidth / 2;
const int screenWidth = 800;
const int screenHeight = 450;
const int halfScreenWidth = screenWidth / 2;
const int halfScreenHeight = screenHeight / 2;
const float rectangleMovement = 550.0f;
const int limit = 35;
extern int player2Points;
extern int player1Points;

extern Rectangle boxP1;
extern Rectangle boxP2;

void CheckColorPlayer1Right();
void CheckColorPlayer1Left();
void CheckColorPlayer2Right();
void CheckColorPlayer2Left();
void DrawRectangles();
void InitRecColor();
void CheckPlayerMovement();
void DrawPlayersPoints();
void InitRecPosition();
#endif 

