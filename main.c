#include "raylib.h"
#include <string.h>

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
	int cellsize = 20;
	int borderWidth = cellsize/20;
	int gridsize = (int)(screenWidth/cellsize)*(int)((screenHeight*0.9)/cellsize);
	char grid[gridsize];
	memset(grid,0,gridsize*sizeof(char));
	InitWindow(screenWidth, screenHeight, "cgol");

	SetTargetFPS(60);               // must be set to one at simulation or smth
	
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT));

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{


		BeginDrawing();

		ClearBackground(GRAY);

		for(int x,y,i=0;i<gridsize;i++)
		{
				x = cellsize * (i%(screenWidth/cellsize)) + borderWidth;
				y = cellsize * (i/(screenWidth/cellsize)) + borderWidth;
				if (!(grid[i])) DrawRectangle(x,y,cellsize-(2*borderWidth),cellsize-(2*borderWidth),BLACK);
				else;
		}

		DrawTextC("(paused)", 0.5, 0.9, screenWidth/20, RED);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
