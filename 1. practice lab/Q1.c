/*
Array-Based Problems
Q1. Search for a Student Record (2D Array)
Store details like Roll Number, Name, and Department of students in a 2D array.
Accept a name as input and display the full record if found; otherwise, show ”Not found”.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<ctype.h>

int main(){
    int n;
    char rollno[20], name[20], department[20];
    
    printf("Enter the numeber of students data to be stored: \n");
    scanf(" %d",&n);

    char arr [n][3][20];

    printf("Enter the rollno, name department of the student\n");
    for(int i=0;i<n;i++){
        scanf("%s %s %s ",rollno,name,department);
        strcpy(arr[i][0],rollno);
        strcpy(arr[i][1],name);
        strcpy(arr[i][2],department);
    }

    char name_check[20];
    printf("Enter the name to be checked for: \n");
    scanf(" %s",name_check);
    int found = 0;

    while(strcmp(name_check,"exit")!=0){
    for(int i=0;i<n;i++){
        if(strcmp(arr[i][1],name_check)==0){
            found = 1;
            printf("Roll Number: %s, Name: %s, Department: %s\n",arr[i][0],arr[i][1],arr[i][2]);
        }
    }
    if(found){printf("Not Found\n");}

    printf("Enter the name to be checked for (or enter exit to end the program): \n");
    scanf(" %s",name_check);
    }

    return 0;
}
