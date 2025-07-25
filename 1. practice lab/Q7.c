/*
Linked List-Based Problems
Q7. Reverse a Sublist Between Positions m and n
Reverse the nodes of a linked list between positions m and n in one pass, without using
extra memory or modifying node values.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<ctype.h>

struct node{
    int val;
    struct node* next;
};

struct node* root = NULL;

struct node* create(int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->val=val;
    new->next=NULL;
    return new;
}

void add_elements(int val){
    struct node* new = create(val);
    if(!root){
        root = new;
        return;
    }
    struct node* temp = root;
    while(temp->next){
        temp=temp->next;
    }
    temp->next = new;
}

struct node* reverseBetween(struct node* head, int m, int n) {
    if (!head || m == n) return head;

    // introduce dummy to prevent any errors
    struct node dummy;  
    dummy.next = head;
    struct node* prev = &dummy;

    for (int i = 1; i < m; i++) {
        prev = prev->next;
    }

    struct node* start = prev->next;
    struct node* then = start->next;

    // Reversing
    for (int i = 0; i < n - m; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy.next;
}

void printList(struct node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main(){
    int n,k,m;
    printf("Enter the number of nodes\n");
    scanf(" %d",&k);
    printf("Enter the value of m and n\n");
    scanf(" %d %d",&m,&n);
    printf("Enter the values of the nodes\n");
    int l;
    for(int i=0;i<k;i++){
        scanf(" %d",&l);
        add_elements(l);
    }

    root = reverseBetween(root, m,n);

    printList(root);

    return 0;
}
