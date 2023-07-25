#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    enum TypeTag type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Enum for arithmetic operations
typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    DIV,
    CONST
} TypeTag;

// Function to create a new Node
Node* makeNode(TypeTag type, int value, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// Function to perform arithmetic operations
int performOperation(TypeTag type, int a, int b) {
    switch (type) {
        case ADD:
            return a + b;
        case MUL:
            return a * b;
        case SUB:
            return a - b;
        case DIV:
            return a / b;
        default:
            return 0;
    }
}

// Function to calculate fibonacci using dynamic programming
int fibonacci(Node* root) {
    if (root == NULL)
        return 0;

    if (root->type == CONST)
        return root->value;

    int leftValue = fibonacci(root->left);
    int rightValue = fibonacci(root->right);

    return performOperation(root->type, leftValue, rightValue);
}

// Function to print the result
void calc(Node* root) {
    int result = fibonacci(root);
    printf("%s : %d\n", (root->type == SUB ? "fibo" : (root->type == ADD ? "add" : (root->type == MUL ? "mul" : "sub"))), result);
}

int main() {
    Node* add = makeNode(ADD, 10, makeNode(CONST, 6, NULL, NULL), NULL);
    Node* mul = makeNode(MUL, 5, makeNode(CONST, 4, NULL, NULL), NULL);
    Node* sub = makeNode(SUB, 0, mul, add);
    Node* fibo = makeNode(SUB, 0, sub, NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    return 0;
}
