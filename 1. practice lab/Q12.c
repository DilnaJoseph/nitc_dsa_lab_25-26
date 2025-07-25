/*
Stack-Based Problems
Q12. Check Balanced Parentheses in an Expression
Write a program that uses a stack to check whether an arithmetic expression contains
balanced parentheses {}, [], and (). Handle nested and multiple types of brackets
properly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct stack {
    char s;
    struct stack* next;
};

struct stack* front = NULL;

bool append(char s) {
    
        if ((s == ')' || s == '}' || s == ']')) {
        if (front == NULL)
            return false;

        if ((s == ')' && front->s == '(') ||
            (s == '}' && front->s == '{') ||
            (s == ']' && front->s == '[')) {
            pop();
            return true;
        } else {
            return false;
        }
    }
    
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    new->s = s;
    new->next = front;
    front = new;
    return true;
}

void pop() {
    if (front == NULL)
        return ;
    struct stack* temp = front;
    front = front->next;
    free(temp);
}

int main() {
    char expression[1000];
    printf("Type the arithematic expression\n");

    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    
    int i =0;
    while(expression[i]!='\0'){
        if (expression[i] == '(' || expression[i] == ')' || expression[i] == '[' || expression[i] == ']' || expression[i] == '{' || expression[i] == '}'){
            if(!append(expression[i])){
                printf("Does not contain balanced parenthesis expression\n");
                return 0;
            }
        }
        i++;
    }
    if (front != NULL) {
        printf("Does not contain balanced parenthesis expression\n");
    } else {
        printf("Contains balanced parenthesis expression\n");
    }
    return 0;
}
