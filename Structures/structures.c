#include<stdio.h>
#include<stdlib.h>

// Structure defination:
    struct student{
        int rollno;
        char name[10];
    }s1;
//⤴ Structure variable declaration style 2:
    
// Structure variable declaration style 3:
    // struct {
    //     int rollno;
    //     char name[10];
    // }s1;

// typedef:
    // typedef struct {
    //     int rollno;
    //     char name[10];
    // }student;

int main(){
    // Structure variable declaration style 1:
    struct student s2;
    s1.rollno=15;
    s2.rollno=10;
    // Structure variable declaration typedef:
        // student s1;
        // s1.rollno=15;

    printf("\nRollno of s1 is : %d",s1.rollno);
    printf("\nRollno of s2 is : %d",s2.rollno);
    return 0;
}