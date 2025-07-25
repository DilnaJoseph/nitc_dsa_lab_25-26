/*
Stack-Based Problems
Q11. Implement Undo Functionality using Stack
Simulate a basic text editor with operations like ”Insert” and ”Delete”. Use a stack to
store the operations and provide an ”Undo” function to reverse the last change.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    char s[20];
    struct stack* next;
};

struct stack* front = NULL;

void append(char s[]) {
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    strcpy(new->s, s);
    new->next = front;
    front = new;
}

struct stack* delete() {
    if (front == NULL)
        return NULL;

    struct stack* temp = front;
    front = front->next;
    temp->next = NULL; // Important: prevent dangling next pointer
    return temp;
}

void undo(struct stack* node) {
    if (node == NULL) return;
    node->next = front;
    front = node;
}

void print_stack() {
    struct stack* temp = front;
    printf("Stack: ");
    while (temp) {
        printf("%s -> ", temp->s);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Enter 'Insert' to add an element\n'Delete' to delete top element\n'Undo' to reverse the last change\n'Exit' to end the program\n");

    char before_command[20] = "", curr_command[20], new_string[20];
    struct stack* deleted_node = NULL;

    while (1) {
        printf("\nCommand: ");
        scanf(" %s", curr_command);

        if (strcmp(curr_command, "Exit") == 0) break;

        if (strcmp(curr_command, "Insert") == 0) {
            scanf(" %s", new_string);
            append(new_string);
            print_stack();
        } else if (strcmp(curr_command, "Delete") == 0) {
            deleted_node = delete();
            if (!deleted_node)
                printf("Stack is empty. Nothing to delete.\n");
            else
                printf("Deleted: %s\n", deleted_node->s);
            print_stack();
        } else if (strcmp(curr_command, "Undo") == 0) {
            if (strcmp(before_command, "") == 0) {
                printf("No changes to undo.\n");
            } else if (strcmp(before_command, "Insert") == 0) {
                deleted_node = delete();  // Undo last insert
                printf("Undo Insert\n");
                print_stack();
            } else if (strcmp(before_command, "Delete") == 0) {
                if (!deleted_node) {
                    printf("No deleted node to restore.\n");
                } else {
                    undo(deleted_node);
                    printf("Undo Delete: %s\n", deleted_node->s);
                    deleted_node = NULL;
                }
                print_stack();
            }
        } else {
            printf("Invalid command.\n");
        }

        strcpy(before_command, curr_command);
    }

    return 0;
}
