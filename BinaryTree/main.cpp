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

    SetTargetFPS(60);

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

        if  (GuiButton(Rectangle{ 0,60,125,25 },"Reset selection"))
        {
            selected = nullptr;
        }

        // Draw

        BeginDrawing();

        ClearBackground(RAYWHITE);

        t.draw(selected);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}