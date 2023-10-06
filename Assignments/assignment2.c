#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Define a structure for the stack
struct Stack {
    struct node* data;
    struct Stack* next;
};

// Function to create a new stack node
struct Stack* createStackNode(struct node* data) {
    struct Stack* stackNode = (struct Stack*)malloc(sizeof(struct Stack));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct Stack** root, struct node* data) {
    struct Stack* stackNode = createStackNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* root) {
    return root == NULL;
}

// Function to pop a node from the stack
struct node* pop(struct Stack** root) {
    if (isEmpty(*root))
        return NULL;
    struct Stack* temp = *root;
    *root = (*root)->next;
    struct node* popped = temp->data;
    free(temp);
    return popped;
}

// Function to perform inorder traversal without recursion
void inorder(struct node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = NULL;
    struct node* current = root;

    while (!isEmpty(stack) || current != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int main() {
    struct node* root = NULL;
    int elm, menu;
    while (1) {
        printf("0. exit, 1. initialize, 2. search, 3. insert, 4. inorder. Input Choice: ");
        scanf("%d", &menu);
        switch (menu) {
            case 0:
                exit(0);
            case 1:
                root = NULL;
                break;
            case 2:
                printf("Give element to search: ");
                scanf("%d", &elm);
                // Implement your search function here
                break;
            case 3:
                printf("Give element to insert: ");
                scanf("%d", &elm);
                root = insert(root, elm);
                break;
            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
