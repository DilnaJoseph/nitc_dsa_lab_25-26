/*
Array-Based Problems
Q2. Find Most Frequent Choice in an MCQ Test
Given a character array representing answer choices (A, B, C, or D) selected by students
in a multiple-choice question, determine which option appears most frequently. In case
of a tie, print the alphabetically first option.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<ctype.h>

int main(){
    int n;
    printf("Enter number of answers: ");
    scanf("%d", &n);

    int answers[4]={0};

    char c;
    printf("Enter the answers (A/B/C/D)\n");
    for(int i=0;i<n;i++){
        scanf(" %c",&c);
        if(c=='A'){answers[0]++;}
        else if(c=='B'){answers[1]++;}
        else if(c=='C'){answers[2]++;}
        else if(c=='D'){answers[3]++;}
    }

    int max = 0;

    for(int i=1;i<4;i++){
        if(answers[i]>answers[max]){
            max =  i;
        }
    }

    if(max==0){printf("Option A");}
    else if(max==1){printf("Option B");}
    else if(max==2){printf("Option C");}
    else {printf("Option D");}

    return 0;
}
