/*
Stack-Based Problems
Q15. Previous Greater Element using Stack
For each element in a given array, find the closest element to its left that is greater
than it. If no such element exists, print ‘-1‘. Implement this efficiently using a stack.
*/

#include <stdio.h>
#include <stdlib.h>

int stack[1000];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if (top != -1) top--;
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void previousGreaterElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Remove all elements smaller than or equal to current
        while (!isEmpty() && peek() <= arr[i]) {
            pop();
        }

        // If stack is empty, no previous greater element
        if (isEmpty()) {
            printf("-1 ");
        } else {
            printf("%d ", peek());
        }

        // Push current element to stack
        push(arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf(" Enter the number of elements in the array\n");
    scanf(" %d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf(" %d",&arr[i]);
    }

    printf("Previous Greater Elements:\n");
    previousGreaterElement(arr, n);

    return 0;
}
