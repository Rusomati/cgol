#include "raylib.h"

int screenWidth = 800;
int screenHeight = 450;

void DrawTextC(char *text, float x, float y, int size, Color color)//draws centered text
{
	int xx = (int)(x*screenWidth);
	int yy = (int)(y*screenHeight);
	DrawText(text, xx - (MeasureText(text, size) / 2), yy, size, color);
}

int main(void)
{

	InitWindow(screenWidth, screenHeight, "cgol");

	SetTargetFPS(60);               // must be set to one at simulation or smth
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT));

		BeginDrawing();

		ClearBackground(GRAY);

		DrawTextC("(paused)", 0.5, 0.9, screenWidth/20, RED);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
