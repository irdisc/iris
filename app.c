#include <raylib.h>

int main(void)
{
    // Initialization
    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKPURPLE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        if (GuiButton((Rectangle){25, 25, 125, 30}, "start"))
        {
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}