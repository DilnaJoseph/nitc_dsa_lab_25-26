/*
Stack-Based Problems
Q14. Sort a Stack using Another Stack (No Arrays)
Sort elements in a stack in ascending order using only one additional stack. Do not
use any array or recursion. Use only standard stack operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct stack {
    int s;
    struct stack* next;
};

struct stack* front = NULL;
struct stack* front1 = NULL;

void append(struct stack** root,int s) {  
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    new->s = s;
    new->next = *root;
    *root = new;
}

int pop(struct stack** root) {
    if (*root == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct stack* temp = *root;
    int val = temp->s;
    *root = temp->next;
    free(temp);
    return val;
}

void arrange(){
    while(front){
    int val = pop(&front);

    while(front1 && front1->s < val){
        int remove = pop(&front1);
         append(&front,remove);
    }
        append(&front1,val);
    }
}

void print_stack() {
    struct stack* temp = front1;
    printf("Stack: ");
    while (temp) {
        printf("%d -> ", temp->s);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n,k;
    printf("Enter the number of nodes\n");
    scanf(" %d",&n);
    printf("Enter the numbers\n");

    for(int i=0;i<n;i++){
        scanf(" %d",&k);
        append(&front,k);
    }
    
    arrange();
    print_stack();
    return 0;
}
 
