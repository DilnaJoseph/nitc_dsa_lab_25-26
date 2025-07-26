/*
Queue-Based Problems
Q19. Implement a Queue Using Two Stacks
Use two stacks to simulate the behavior of a queue. Implement enqueue and dequeue
such that they preserve FIFO order. Use only standard stack operations
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h> 

int stack1[1000];
int stack2[1000];
int top1=-1,top2=-1;

void push(int arr[],int* top,int val){
    arr[++(*top)]=val;
}

int pop(int arr[],int* top ){
    if(*top==-1){
        printf("stack is empty\n ");
        return -1;
    }
    int temp = arr[(*top)--];
    return temp;

}


int main(){
    printf("Enter the number of elements: \n");
    int n;
    scanf(" %d",&n);

    for(int i=0;i<n;i++){
        int val;
        scanf(" %d",&val);
        push(stack1,&top1,val);
    }

    printf("Enter 'enqueue' to add an element \n 'dequeue' to remove an element\n 'print' to print the element \n and 'exit' to end the program\n");

    char command[20];
    scanf(" %s",command);

    while((strcmp(command,"exit")!=0)){
    if(strcmp(command,"enqueue")==0){
        int l;
        printf("Enter the value you want to add to the list: \n");
        scanf(" %d",&l);
        int val;
        while(top1!=-1){
            push(stack2,&top2,pop(stack1,&top1));
        }
        push(stack2,&top2,l);
        while(top2!=-1){
            push(stack1,&top1,pop(stack2,&top2));
        }
    }else if(strcmp(command,"dequeue")==0){
        int val = pop(stack1,&top1);
    }else if(strcmp(command,"print")==0){
        while(top1!=-1){
            push(stack2,&top2,pop(stack1,&top1));
        }
        
        while(top2!=-1){
            int val1 = pop(stack2,&top2);
        printf("%d ",val1);
            push(stack1,&top1,val1);
        }
    }
    printf("Enter your commmand\n");
    scanf(" %s",command);
    }
    return 0;
}
