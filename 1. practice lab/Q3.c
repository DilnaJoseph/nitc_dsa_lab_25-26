/*
Array-Based Problems
Q3. Left Rotate Array by k Positions (In-place)
Write a function to rotate a 1D integer array to the left by k positions without using
any extra array. Ensure the result is obtained in-place.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
int k,n;
printf("Enter the total number of numbers and how many positions to be rotated by\n");
scanf(" %d %d",&n,&k);
int arr[n];

printf("Enter the elements of the array\n");
for(int i=0;i<n;i++){
scanf(" %d",&arr[i]); 
}

// rotating to left k times
for(int i=0;i<k;i++){
int temp = arr[0];
//rotate to left by one
for(int i=1;i<n;i++){
arr[i-1] = arr[i];
}
arr[n-1] = temp; 
}

//print it out
for(int i=0;i<n;i++){
printf(" %d",arr[i]); 
}

return 0 ;
}
