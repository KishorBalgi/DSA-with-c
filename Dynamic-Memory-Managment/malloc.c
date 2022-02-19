// 📌SYNTAX : ptr = (cast-type*) malloc(byte-size);
// malloc - "Memory Allocation"

#include<stdio.h>
#include<stdlib.h>

int main(){
    // Allocating a memory block of size int*5:
    int *ptr=(int*)malloc(5*sizeof(int));

    printf("Value in ptr : %d",*ptr);
    printf("\nSize of ptr : %d",sizeof(ptr));
    return 0;
}