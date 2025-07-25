/*
Stack-Based Problems
Q13. Evaluate a Postfix Expression using Stack
Given a postfix expression with single-digit integers and operators (‘+‘, ‘-‘, ‘*‘, ‘/‘),
use a stack to evaluate the expression and return the final result.
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

void append(int s) {  
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    new->s = s;
    new->next = front;
    front = new;
}

int pop() {
    if (front == NULL)
    {    printf("stack is empty\n");
        return 0;}
    struct stack* temp = front;
    int val = temp->s;
    front = front->next;
    free(temp);
    return val;
}

void evaluate(char ch){
    if(isdigit(ch)){
        append(ch-'0');
    }else if(ch=='-'||ch=='+'||ch=='/'||ch=='*'){
        int val1 = pop();
        int val2 = pop();
        int result;
        switch(ch){
            case '+': result = val2 + val1; break;
            case '-': result = val2 - val1; break;
            case '*': result = val2 * val1; break;
            case '/':
                if (val1 == 0) {
                    printf("Division by zero not possible\n");
                    return 0;
                }
                result = val2 / val1;
                break;
        }
        append (result);
    }
}
int main() {
    char expression[1000];
    printf("Type the postfix expression\n");

    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    int sum = 0,i=0,numbers=0;

    while(expression[i]!='\0'){
        evaluate(expression[i]);
        i++;
    }
    sum = pop();
    printf("The sum is: %d\n",sum);
    
    return 0;
}
