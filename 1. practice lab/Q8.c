/*
Linked List-Based Problems
Q8. Add Two Numbers Represented by Linked Lists
Two numbers are stored in reverse order as linked lists; add them and return the sum
as a new linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* root1 = NULL;
struct node* root2 = NULL;

struct node* create(int val) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->val = val;
    new->next = NULL;
    return new;
}

void add_elements(struct node** node, int val) {
    struct node* newNode = create(val);
    if (*node == NULL) {
        *node = newNode;
        return;
    }
    struct node* temp = *node;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    struct node dummy;
    struct node* curr = &dummy;
    dummy.next = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = create(sum % 10);
        curr = curr->next;
    }
    return dummy.next;
}


void printList(struct node* head) {
    while (head) {
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Enter the number of digits in both numbers: ");
    scanf("%d %d", &n, &m);

    printf("Enter digits for the first number : ");
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add_elements(&root1, val);
    }

    printf("Enter digits for the second number : ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        add_elements(&root2, val);
    }

    struct node* result = addTwoNumbers(root1, root2);
    printf("The sum is: ");
    printList(result);

    return 0;
}
