#include "raylib.h"
void DrawTextC(char *text, int x, int y, int size, Color color)//draws centered text
{
	DrawText(text, x - (MeasureText(text, size) / 2), y,size, color);
}
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "cgol");

    SetTargetFPS(60);               // must be set to one at simulation or smth
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT));

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTextC("(paused)", screenWidth/2, screenHeight * 9 / 10, screenWidth/20, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
