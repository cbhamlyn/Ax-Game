#include "raylib.h"
int main()
{
    // Window dimensions
    int width = 800;
    int height = 450;
    InitWindow(width, height, "Axe Game");

    // Circle dimensions
    int circle_x{200};
    int circle_y{height - 50};
    int circle_rad{25};
    // Circle edges
    int l_circle_x{circle_x - circle_rad};
    int r_circle_x{circle_x + circle_rad};
    int u_circle_y{circle_y - circle_rad};
    int b_circle_y{circle_y + circle_rad};
    
    // axe
    int axe_x{400};
    int axe_y{0};
    int axe_width{50};
    int axe_height{50};
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_width};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_height};
    // axe options
    int axe_speed{10};
    bool coll_with_axe{false};
    
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        if (coll_with_axe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            // Game logic starts

            // Update edges
            l_circle_x = circle_x - circle_rad;
            r_circle_x = circle_x + circle_rad;
            u_circle_y = circle_y - circle_rad;
            b_circle_y = circle_y + circle_rad;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_width;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_height;

            DrawCircle(circle_x, circle_y, circle_rad, BLUE);
            DrawRectangle(axe_x, axe_y, axe_width, axe_height, RED);
            
            // Move the axe
            axe_y += axe_speed;
            if (axe_y > height)
            {
                axe_y = 0;
                axe_x = GetRandomValue(0, width);
                axe_speed += 1;
            }
            if ( b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x )
            {
                coll_with_axe = true;
            }
            // Move the circle
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }            
        }
        // Game logic ends
        EndDrawing();
    }
    CloseWindow();
}