#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "include/raylib.h"

typedef struct Node {
    float x, y;           // Position
    float radius;         // Circle radius
    float angle;         // Current angle
    float angularSpeed;  // Rotation speed
    Color color;         // Circle color
    struct Node* next;   // Next node
    struct Node* prev;   // Previous node
} Node;
//     float x, y; // Position
//     float angle; // Rotation angle
//     float speed; // Angular speed
//     float radius; // Circle radius
//     struct Node *prev, *next; // Linked list pointers
// } Node;

// Function prototypes
Node* createNode(float radius, float speed);
void addNode(Node **head, float radius, float speed);
void removeNode(Node **head);
void updateNodes(Node *head);
void drawNodes(Node *head);

#endif
