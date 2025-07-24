/*
Linked List-Based Problems
Q9. Partition List Around a Value x
Rearrange the list so that all nodes less than x come before nodes greater than or equal
to x, while preserving their original order.
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
struct node* root1 = NULL;
struct node* root2 = NULL;

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

void add_left(int val){
    struct node* new = create(val);
    if(!root1){
        root1 = new;
        return;
    }
    struct node* temp = root1;
    while(temp->next){
        temp=temp->next;
    }
    temp->next = new;
}

void add_right(int val){
    struct node* new = create(val);
    if(!root2){
        root2 = new;
        return;
    }
    struct node* temp = root2;
    while(temp->next){
        temp=temp->next;
    }
    temp->next = new;    
}

int main(){
    int n,m;
    printf("Enter the numeber of nodes\n");
    scanf(" %d",&n);
    printf("Enter the number about which you want to split\n");
    scanf("%d",&m);

    printf("Enter the elements\n");
    int l;
    for(int i=0;i<n;i++){
        scanf(" %d",&l);
        add_elements(l);
    }

    struct node *temp = root;
    while(temp){
        if(temp->val<m){
            add_left(temp->val);
        }else{
            add_right(temp->val);
        }
        temp=temp->next;
    }

    temp = root1;
    printf("The first list \n");
    while(temp){
        printf("%d ",temp->val);
        temp=temp->next;
    }

    temp = root2;
    printf("The second list \n");
    while(temp){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    return 0;
}
