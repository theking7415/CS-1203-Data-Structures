#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
typedef struct node {
    int data;
    struct node* next;
} NODE;

// Define a structure for the queue
typedef struct queue {
    NODE* front;
    NODE* rear;
} QUEUE;

// Function to create an empty queue
QUEUE* createQueue() {
    QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
    if (!q) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

// Function to insert an element into the queue
void insert(QUEUE* q, int elm) {
    // Create a new node
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = elm;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        // Otherwise, update the rear pointer and link the new node
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to delete an element from the queue
void delete(QUEUE* q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    // Remove the front node and update the front pointer
    NODE* temp = q->front;
    q->front = q->front->next;
    free(temp);
}

// Function to print the elements in the queue
void printQueue(QUEUE* q) {
    NODE* current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    QUEUE* q = createQueue();
    int choice, element;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Print the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to insert: ");
                scanf("%d", &element);
                insert(q, element);
                break;
            case 2:
                delete(q);
                break;
            case 3:
                printQueue(q);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free memory before exiting
    while (q->front != NULL) {
        delete(q);
    }
    free(q);

    return 0;
}

// Run 1
Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 1
Enter an element to insert: 10

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 1
Enter an element to insert: 20

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 3
Queue: 10 20 

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 2

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 3
Queue: 20 

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 4
Exiting the program.

// Run 2
Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 1
Enter an element to insert: 5

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 1
Enter an element to insert: 15

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 1
Enter an element to insert: 25

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 3
Queue: 5 15 25 

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 2

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 3
Queue: 15 25 

Queue Menu:
1. Insert an element
2. Delete an element
3. Print the queue
4. Exit
Enter your choice: 4
Exiting the program.

