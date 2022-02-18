// SYNTAX : free(ptr);
// free - frees the allocated memory
#include<stdio.h>
#include<stdlib.h>

int main(){
    // Allocating a memory block of size int*5:
    int *ptr=(int*)malloc(5*sizeof(int));

    // Re-allocating a memory block of size int*10:
    ptr=(int*)malloc(10*sizeof(int));
    return 0;
}