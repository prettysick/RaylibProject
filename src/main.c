#include "include/raylib.h"
#include "linked_list.h"
#include <stdio.h>
#include <math.h>

int main(void) {
    InitWindow(800, 600, "Rotating Circles");
    SetTargetFPS(60);

    Node *head = createNode(20, 0); // Larger root node, no rotation
    head->x = 400;
    head->y = 300;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_A)) {
            addNode(&head, 15, 0.03f); // Larger radius, faster rotation
        }
        if (IsKeyPressed(KEY_R)) {
            removeNode(&head);
        }

        updateNodes(head);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawNodes(head);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// int main(void) {
//     InitWindow(800, 600, "Rotating Circles");
//     SetTargetFPS(60);

//     Node *head = createNode(5, 0); // Root node
//     head->x = 400;  // Center of the window
//     head->y = 300;  // Center of the window

//     while (!WindowShouldClose()) {
//         // Add and remove nodes with keyboard input
//         // if (IsKeyPressed(KEY_A)) addNode(&head, 10 + GetRandomValue(0, 10), 0.02f); ilk versiyon
//         if (IsKeyPressed(KEY_A)) addNode(&head, 10, 0.02f); // Smaller circles
//         if (IsKeyPressed(KEY_R)) removeNode(&head);

//         updateNodes(head);

//         BeginDrawing();
//         ClearBackground(RAYWHITE);
//         drawNodes(head);
//         EndDrawing();
//     }

//     CloseWindow();
//     return 0;
// }
