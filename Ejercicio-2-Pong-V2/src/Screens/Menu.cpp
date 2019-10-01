#include "Menu.h"

#include "raylib.h"

#include <iostream>

#include "Game.h"
#include "Palette.h"

static void DrawMenu();
static void CheckColorInput();
static void UpdateMenu();
void RunMenu()
{
	UpdateMenu();
}
static void DrawMenu()
{
	ClearBackground(BLACK);
	DrawText("PONG", 360, 50, 20, RAYWHITE);
	
	DrawText("SELECT BAR COLOR USING 'A' 'D' OR ARROWS", 175, 100, 20, RAYWHITE);

	DrawText("PRESS ENTER", 310, 130, 20, RAYWHITE);
}
static void CheckColorInput()
{
	if (IsKeyPressed(KEY_D))
	{
		CheckColorPlayer1Right();
	}

	if (IsKeyPressed(KEY_A))
	{
		CheckColorPlayer1Left();
	}
	if (IsKeyPressed(KEY_RIGHT))
	{
		CheckColorPlayer2Right();
	}
	if (IsKeyPressed(KEY_LEFT))
	{
		CheckColorPlayer2Left();
	}

}
void UpdateMenu() 
{
	// Check Input and Update
	//----------------------------------------------------------
	CheckColorInput();
	BeginDrawing();
	DrawMenu();
	DrawRectangles();
	EndDrawing();
	if (IsKeyPressed(KEY_ENTER))
	{
		menu = false;
		playing = true;
	}
}