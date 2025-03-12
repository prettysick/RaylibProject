#include "linked_list.h"
#include <stdlib.h>
#include <math.h>
#include "include/raylib.h"

Node* createNode(float radius, float angularSpeed) {
    Node* newNode = malloc(sizeof(Node));
    // Limit maximum circle size to prevent overlap issues
    newNode->radius = GetRandomValue(5, 15);  // Smaller range of radii
    newNode->angle = GetRandomValue(0, 360) * DEG2RAD;
    // Increase minimum orbital speed for more dynamic movement
    newNode->angularSpeed = GetRandomValue(2, 6) * 0.02f;
    newNode->color = (Color){GetRandomValue(50, 255), GetRandomValue(50, 255), GetRandomValue(50, 255), 255};
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
   
}

void updateNodes(Node* head) {
    if (head == NULL) return;
    
    Node* current = head->next;
    Node* parent = head;
    
    while (current != NULL) {
        // Update rotation angle
        current->angle += current->angularSpeed;
        
         // Fixed minimum distance between circle centers
        float minDistance = 30.0f;  // Constant spacing regardless of circle sizes
        
        // Update position using the increased orbital distance
        current->x = parent->x + minDistance * cosf(current->angle);
        current->y = parent->y + minDistance * sinf(current->angle);
        
        // Move to next pair
        parent = current;
        current = current->next;
    }
}


void addNode(Node** head, float radius, float angularSpeed) {
    Node* newNode = createNode(radius, angularSpeed);
    Node* current = *head;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;  // Set the prev pointer
}

void removeNode(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // Don't remove if it's the root node or list is empty
        return;
    }

    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

}
