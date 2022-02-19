// 📌SYNTAX : ptr=realloc(ptr,10*sizeof(int));
// realloc - "Re-allocate"
#include<stdio.h>
#include<stdlib.h>

int main(){
    // Allocating a memory block of size int*5:
    int *ptr=(int*)malloc(5*sizeof(int));

    // Re-allocating a memory block of size int*10:
    ptr=realloc(ptr,10*sizeof(int));
    return 0;
}