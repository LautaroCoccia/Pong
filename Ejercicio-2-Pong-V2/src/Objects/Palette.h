#ifndef PALETTE_H
#define PALETTE_H
#include "raylib.h"

extern float rectangleMovement;

const int maxScore = 3;
const int commonRectangleHeight = 90;
const int rentangleWidth = 15;
const int halfRectangleHeight = commonRectangleHeight / 2;
const int halfRectangleWidth = rentangleWidth / 2;
const int BaseScreenWidth = 800;
const int BaseScreenHeight = 450;
const int halfScreenWidth = BaseScreenWidth / 2;
const int halfScreenHeight = BaseScreenHeight / 2;

const int limit = 35;
extern int player2Points;
extern int player1Points;

extern Rectangle boxP1;
extern Rectangle boxP2;
extern void NormalizedPowerUpedPalettesPosition();
extern void InitRecColor();
extern void CheckColorPlayer1Right();
extern void CheckColorPlayer1Left();
extern void CheckColorPlayer2Right();
extern void CheckColorPlayer2Left();
extern void InitRecPositionNScore();
extern void SetPalettesAspectRatio();
extern void CheckPlayerMovement();
extern void DrawRectangles();
extern void DrawPlayersPoints();
#endif 

