/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include "Tree.h"


int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Binary tree");

    Tree t;

    int selectedValue = 0;

    TreeNode* selected = nullptr;

    Vector2 offset = Vector2{ 0,0 };

    SetTargetFPS(60);

    t.insert(50);

    for (size_t i = 0; i < 20; i++)
    {
        t.insert(GetRandomValue(0, 100));
    }

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        GuiValueBox(Rectangle{ 0,0,125,25 }, "number", &selectedValue, 0, INT_MAX, true);

        if (GuiButton(Rectangle{ 130,0,125,25 },GuiIconText(RICON_FILE_SAVE, "Insert")))
        {
            t.insert(selectedValue);
        }

        if (GuiButton(Rectangle{ 130,30,125,25 },GuiIconText(RICON_FILE_DELETE, "Remove")))
        {
            if (selected != nullptr && selected->getValue() == selectedValue)
            {
                selected = nullptr;
            }
            t.remove(selectedValue);
        }

        if (GuiButton(Rectangle{ 0,30,125,25 },"Find"))
        {
            selected = t.find(selectedValue);
        }

        if  (GuiButton(Rectangle{ 0,60,125,25 },"Clear selection"))
        {
            selected = nullptr;
        }

        if (IsKeyPressed(KEY_LEFT))
        {
            offset.x += 20;
        }
        if (IsKeyPressed(KEY_RIGHT))
        {
            offset.x -= 20;
        }
        if (IsKeyPressed(KEY_UP))
        {
            offset.y += 20;
        }
        if (IsKeyPressed(KEY_DOWN))
        {
            offset.y -= 20;
        }

        // Draw

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(offset.x, offset.y, 5, 5, BLACK);

        DrawRectangle(screenWidth + offset.x - 5, offset.y, 5, 5, BLACK);

        DrawRectangle(offset.x, screenHeight + offset.y - 5, 5, 5, BLACK);

        DrawRectangle(screenWidth + offset.x - 5, screenHeight + offset.y - 5, 5, 5, BLACK);

        t.draw(offset, selected);

        DrawText("Move view with arrow keys", 5, 100, 14, GRAY);

        EndDrawing();

        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}