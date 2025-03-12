#include "include/raylib.h"
#include "linked_list.h"
#include <stdio.h>
#include <math.h>

void drawNodes(Node *head) {
     Node* current = head;
    
    while (current->next != NULL) {
        // Draw connecting line first (behind circles)
        DrawLine(
            (int)current->x, 
            (int)current->y, 
            (int)current->next->x, 
            (int)current->next->y, 
            DARKGRAY
        );
        
        // Draw the circles
        DrawCircle(
            (int)current->x, 
            (int)current->y, 
            current->radius, 
            current->color
        );
        
        current = current->next;
    }
    
    // Draw the last circle
    DrawCircle(
        (int)current->x, 
        (int)current->y, 
        current->radius, 
        current->color
    );
}
//     if (!head) return; -----------------
    
//     Node *current = head;
//      // Root node stays at the center
//      // Root node (small dot at center)
//     DrawCircle(current->x, current->y, 5, BLACK);
//     current->x = 400;
//     current->y = 300;

//     while (current->next) {
//         Node *nextNode = current->next;

//         // Update rotation angle
//         nextNode->angle += nextNode->angularSpeed;

//         // Calculate new position using trigonometry
//         nextNode->x = current->x + cos(nextNode->angle) * nextNode->radius;
//         nextNode->y = current->y + sin(nextNode->angle) * nextNode->radius;

//         // Draw connection line
//         DrawLine(current->x, current->y, nextNode->x, nextNode->y, DARKGRAY);
        
//         // Draw circle
//         DrawCircle(nextNode->x, nextNode->y, nextNode->radius, RED);
        
//         // Move to the next node
//         current = nextNode;
//     }
// } --------------

    // Vector2 prevPos = { current->x, current->y };

    // while (current) {
    //     // Update position
    //     current->angle += current->speed;  // Update rotation angle
    //     current->x = prevPos.x + cos(current->angle) * current->radius;
    //     current->y = prevPos.y + sin(current->angle) * current->radius;

    //     // Draw connection line
    //     DrawLine(prevPos.x, prevPos.y, current->x, current->y, GRAY);
        
    //     // Draw circle
    //     DrawCircle(current->x, current->y, current->radius, RED);
        
    //     prevPos.x = current->x;
    //     prevPos.y = current->y;
    //     current = current->next;
    // }

