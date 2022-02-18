#include<stdio.h>
#include<stdlib.h>
int sum(int a ,int b){
    return a+b;
}
int main(){
    // Creating a pointer to function sum:
    int (*sumptr)(int,int);
    sumptr=sum;
    
    printf("Sum : %d",sumptr(10,5));
    return 0;
}