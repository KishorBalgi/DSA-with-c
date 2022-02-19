// 📌SYNTAX : free(ptr);
// free - "free the allocated memory"
#include<stdio.h>
#include<stdlib.h>

int main(){
    // Allocating 5 memory block of size float :
    float *ptr=(float*)calloc(5,sizeof(float));

    printf("Value in ptr : %d",*ptr);
    printf("\nSize of ptr : %d",sizeof(ptr));
    free(ptr);
    return 0;
}