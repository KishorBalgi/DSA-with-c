#include<stdio.h>
#include<stdlib.h>

int main(){
    int a=10;
    
    int *ptr=&a;
    // NULL pointer:
    int *p=NULL;
    // Void pointer:
    void *vp=NULL;
    // Wild pointer:
    int *w;
    printf("Pointer content(ptr) : %d value(*ptr) : %d",ptr,*ptr);
    // For NULL pointer:
    printf("Null pointer contains(p): %d value(*p) : %d",p,*p);
    // For Void pointer:
    printf("Void pointer size: %d",sizeof(vp));
    // For wild pointer:
    printf("%d",*w);
    return 0;
}