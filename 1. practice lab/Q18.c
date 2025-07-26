/*
Queue-Based Problems
Q18. Interleave Two Halves of a Queue (You can Use an additional Stack)
You are given a queue with 2n elements. Rearrange the queue so that elements from
the first and second halves appear alternately. For example, convert [1,2,3,4,5,6]
into [1,4,2,5,3,6]. Use only standard stack and queue operations.
*/

#include <stdio.h>
#include <stdlib.h>

int queue[1000];
int stack1[1000];

int front = -1, rear = -1, top = -1;

// Enqueue
void enqueue(int val) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = val;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// Push to stack
void push(int val) {
    stack1[++top] = val;
}

// Pop from stack
int pop() {
    if (top == -1) {
        return -1;
    }
    return stack1[top--];
}

// Interleave function
void interleave(int n) {
    int half = n / 2;

    // Step 1: Push first half into stack
    for (int i = 0; i < half; i++) {
        push(dequeue());
    }

    // Step 2: Enqueue back from stack
    while (top != -1) {
        enqueue(pop());
    }

    // Step 3: Move first half of queue to back
    for (int i = 0; i < half; i++) {
        enqueue(dequeue());
    }

    // Step 4: Push first half again into stack
    for (int i = 0; i < half; i++) {
        push(dequeue());
    }

    // Step 5: Interleave stack and queue
    int tempQueue[1000];
    int tempRear = -1;

    while (top != -1) {
        tempQueue[++tempRear] = pop();      // from stack (first half)
        tempQueue[++tempRear] = dequeue();  // from queue (second half)
    }

    // Step 6: Refill the main queue
    front = 0;
    rear = tempRear;
    for (int i = 0; i <= rear; i++) {
        queue[i] = tempQueue[i];
    }
}

// Display the queue
void displayQueue() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    printf("Enter the number of elements (even number): ");
    int n;
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Number of elements must be even for interleaving.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }

    interleave(n);

    printf("Interleaved queue:\n");
    displayQueue();

    return 0;
}
