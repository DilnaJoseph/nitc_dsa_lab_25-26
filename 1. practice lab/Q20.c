/*
Q20. Generate Binary Representation of Number n
Given a positive integer n, use a queue to generate the binary representation of n. Use
simple arithmetic and queue operations only (no library functions).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char queue[1000][1000];
int front = 0, rear = 0;

void enqueue(char* str) {
    strcpy(queue[rear++], str);
}

char* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);


    enqueue("1");

    char* current;
    for (int i = 1; i < n; i++) {
        current = dequeue();

        char temp0[1000], temp1[1000];
        strcpy(temp0, current);
        strcpy(temp1, current);
        strcat(temp0, "0");
        strcat(temp1, "1");

        enqueue(temp0);
        enqueue(temp1);
    }
    current = dequeue();
        printf("%s\n", current);

    return 0;
}
