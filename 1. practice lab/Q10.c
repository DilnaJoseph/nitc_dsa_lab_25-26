/*
Linked List-Based Problems
Q10. Check if Linked List is a Palindrome
Determine whether the linked list forms a palindrome (reads the same forwards and
backwards).
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<ctype.h>

struct node{
    int val;
    struct node* next,*prev;
};

struct node* root = NULL;

struct node* create(int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->val=val;
    new->next=new->prev=NULL;
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
    new->prev=temp;
}

int main(){
    int n,k,m;
    printf("Enter the number of nodes\n");
    scanf(" %d",&k);
    
    int l;
    for(int i=0;i<k;i++){
        scanf(" %d",&l);
        add_elements(l);
    }

    struct node *first=root, *last=NULL, *temp=root;
    
    while(temp){
        last = temp;
        temp=temp->next;
    }

    for(int i=0;i<n/2;i++){
    if(first->val!=last->val){
        printf("Not a palindrome.\n");
        return;
    }
    first = first->next;
    last = last->prev;
    }
    printf("It is a palindrome.\n");
    return 0;
}
