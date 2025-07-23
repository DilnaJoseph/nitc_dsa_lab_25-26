/*
Queue-Based Problems
Q16. Simulate Ticket Counter Using Queue
Create a queue-based program to simulate people arriving at and leaving a ticket
counter. Implement enqueue, dequeue, and display the current queue state after each
operation.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int rear=-1,front=-1;

void display(int tokens[]){
 if (front == -1 || front > rear) {
     printf("Queue is empty!\n");
     return;
 }
 printf("Queue: ");
for(int i=front;i<=rear;i++){
    printf("%d ",tokens[i]);
  }
}

void enqueue(int tokens[],int no){
 if (rear == n - 1) {
     printf("Queue is full!\n");
    return;
 }
 if (front == -1) front = 0;
 tokens[++rear] = no;
}

void dequeue(int tokens[]){
if (front == -1 || front > rear) {
    printf("Queue is empty!\n");
    return;
}
  front++;
}


int main(){
int n;
printf("Enter the size of queue: ");
scanf(" %d",&n);
int tokens[n];

printf("enter the folowing accordingly 0:exit\n 1: enqueue\n 2:dequeue\n");

int m;
scanf(" %d",&m);

while(m!=0){
if(m==1){
  int no;
  printf("Enter number to enqueue: ");
  scanf(" %d",&no);
  enqueue(tokens,no);
  display(tokens);
 }
else if(m==2){
  dequeue(tokens);
  display(tokens);
 }
  printf("Enter command: ");
  scanf(" %d",&m);
}
return 0 ;}
