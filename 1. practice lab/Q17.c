/*
Queue-Based Problems
Q17. Reverse First k Elements of a Queue (You can Use an additional Stack)
Given a queue of integers and an integer k, reverse the first k elements of the queue
while keeping the order of the remaining elements unchanged. Use only standard stack
and queue operations.
*/

#include <stdio.h>
#include <stdlib.h>

int rear = -1, front = -1;

int stack[1000];
int top = -1;

// Stack functions
void push(int val) {
    stack[++top] = val;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// Queue functions
void enqueue(int tokens[], int val) {
    if (front == -1) front = 0;
    tokens[++rear] = val;
}

int dequeue(int tokens[]) {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return tokens[front++];
}

void displayQueue(int tokens[]) {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", tokens[i]);
    }
    printf("\n");
}

// Function to reverse first k elements
void reverse(int tokens[], int k) {
    if (front == -1 || front + k - 1 > rear) {
        printf("Invalid k\n");
        return;
    }

    // Step 1: Push first k elements to stack
    for (int i = 0; i < k; i++) {
        push(dequeue(tokens));
    }

    // Step 2: Pop from stack and enqueue at rear
    int tempQueue[1000];
    int tempRear = -1;

    while (!isEmpty()) {
        tempQueue[++tempRear] = pop();
    }

    // Step 3: Add remaining queue elements
    while (front <= rear) {
        tempQueue[++tempRear] = dequeue(tokens);
    }

    // Step 4: Copy back to original queue
    front = 0;
    rear = tempRear;
    for (int i = 0; i <= rear; i++) {
        tokens[i] = tempQueue[i];
    }
}

int main() {
    int n, k;
    printf("Enter the size of queue: ");
    scanf("%d", &n);

    int tokens[1000];  // Large enough buffer
    front = 0; rear = -1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(tokens, val);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Original Queue:\n");
    displayQueue(tokens);

    reverse(tokens, k);

    printf("Queue after reversing first %d elements:\n", k);
    displayQueue(tokens);

    return 0;
}
