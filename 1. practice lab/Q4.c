/*
Array-Based Problems
Q4. Find Store with Maximum Sales (2D Array)
You are given a 2D integer array where each row represents monthly sales for a different
store. Find and display the row index and total sales of the store with the highest
overall sales.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<ctype.h>

int main(){
    int n;

    printf("Enter the total number of stores: \n");
    scanf(" %d",&n);

    int sum = 0,arr[n][12],value,sum_arr[n];
    printf("enter the sales for each store\n");
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=0;j<12;j++){
          scanf(" %d",&value);
          arr[i][j] = value;
          sum+=value;
        }
        sum_arr[i] = sum;
    }

    int max = sum_arr[0],index=0;
    for(int i=1;i<n;i++){
        if(sum_arr[i]>max){
            max = sum_arr[i];
            index = i;
        }
    }

    printf("The store index with highest sales is %d and the sales is %d\n",index,max);
    return 0 ;
}
