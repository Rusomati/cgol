#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int screenWidth = 475;
int screenHeight = 450;

void DrawTextC(char *text, float x, float y, int size, Color color)//draws centered text
{
	int xx = (int)(x*screenWidth);
	int yy = (int)(y*screenHeight);
	DrawText(text, xx - (MeasureText(text, size) / 2), yy, size, color);
}

int getCell(char *cell, int i, int ii, int width, int height)
{
	char res = 0;
	//a lot of windows for optimisation too lazy tho
	//the code is ugly af i know
	if(!(i/width)&&(ii<=2));//top
	else if(!(i%width)&&(!ii||ii==3||ii==5));//left
	else if(!((i+1)%width)&&(ii==2||ii==4||ii==7));//right
	else if(((i/width)==(height-1))&&ii>=5);//bottom
	else
	{
		if (!ii) res = *((cell-width)-1);
		else if(ii==1) res = *(cell-width);
		else if(ii==2) res = *(cell-width+1);
		else if(ii==3) res = *(cell-1);
		else if(ii==4) res = *(cell+1);
		else if(ii==5) res = *(cell+width-1);
		else if(ii==6) res = *(cell+width);
		else res = *(cell+width+1);
	}
	return res;
}

void cellEval(char *cell,char *cell2, int i, int width, int height)
{
	int adjacentC = 0;
	for (int ii = 0;ii<8;ii++)
	{
		adjacentC+=getCell(cell,i,ii,width,height);
	}
	if (adjacentC == 3) *cell2=1;
	else if (adjacentC == 2 && *cell) *cell2=1;
	else *cell2 = 0;
}

int main(void)
{
	char is_paused = 1;
	int cellsize = 15;
	int borderWidth = (cellsize/20) ? cellsize/20 : 1;
	int gridsize = (int)(screenWidth/cellsize)*(int)((screenHeight*0.9)/cellsize);
	char *grid = calloc(gridsize,sizeof(char));
	char *grid2 = calloc(gridsize,sizeof(char));
	InitWindow(screenWidth, screenHeight, "cgol");
	
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		SetTargetFPS(is_paused ? 60 : 4);
		if(IsKeyPressed(KEY_SPACE))is_paused=!is_paused;

		if (is_paused)
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			grid[((GetMouseY()/cellsize) * (screenWidth/cellsize)) + (GetMouseX()/cellsize)]=1;
			if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
			grid[((GetMouseY()/cellsize) * (screenWidth/cellsize)) + (GetMouseX()/cellsize)]=0;
		}
		else
		{
			for (int i=0;i<gridsize;i++)
			{
				cellEval(&grid[i],&grid2[i],i,(int)(screenWidth/cellsize),(int)(screenHeight*0.9/cellsize));
			}
				memcpy(grid,grid2,gridsize*sizeof(char));//gross i know
		}

		BeginDrawing();

		ClearBackground(GRAY);

		for(int x,y,i=0;i<gridsize;i++)
		{
				x = cellsize * (i%(screenWidth/cellsize)) + borderWidth;
				y = cellsize * (i/(screenWidth/cellsize)) + borderWidth;
				if (!(grid[i])) DrawRectangle(x,y,cellsize-(2*borderWidth),cellsize-(2*borderWidth),BLACK);
				else DrawRectangle(x,y,cellsize-(2*borderWidth),cellsize-(2*borderWidth),WHITE);
		}

		if (is_paused) DrawTextC("(paused)", 0.5, 0.9, screenWidth/20, RED);

		EndDrawing();
	}

	CloseWindow();
	free(grid);
	free(grid2);

	return 0;
}
