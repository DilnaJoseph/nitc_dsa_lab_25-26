/*
Array-Based Problems
Q5. Sort Product Names by String Length
Given a list of product names stored in a string array, sort them based on their lengths
in ascending order. If two strings have the same length, maintain their original order.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<ctype.h>

int main(){
    int n;

    printf("Enter the number of products \n");
    scanf(" %d",&n);

    char products[n][20];

    printf("Enter the name of the products \n");

    char prod[20];
    for(int i=0;i<n;i++){
        scanf(" %s",prod);
        strcpy(products[i],prod);
    }

    // insertion sort
    for (int i = 1; i < n; i++) {
        char temp[20];
        strcpy(temp, products[i]);
        int len = strlen(temp);

        int j = i - 1;
        while (j >= 0 && strlen(products[j]) > len) {
            strcpy(products[j + 1], products[j]);
            j--;
        }
        strcpy(products[j + 1], temp);
    }

    printf("Sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", products[i]);
    }

    return 0;
}
