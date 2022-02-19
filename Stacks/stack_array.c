// 📌Headers:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 📌Globals:
#define SIZE 5
int s[SIZE];
int top=-1;

// 📌Push Function:
bool push(int item){
    if(top==SIZE-1) return false;
    s[++top]=item;
    return true;
}
// 📌Pop Function:
int pop(){
    if(top==-1) return -1;
    return s[top--];
}
// 📌isEmpty Function:
bool isEmpty(){
    if(top==-1) return true;
    return false;
}
// 📌isFull Function:
bool isFull(){
    if(top==SIZE-1) return true;
    return false;
}
// 📌Peek Function:
int peek(){
    if(top==-1) return -1;
    return s[top];
}
// 📌Main function:
int main(){
    int choice,item;
    while(1){
        printf("\nStack Options:\n\n1.Push\n2.Pop\n3.isFull\n4.isEmpty\n5.Peek\n6.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
        // Push:
        case 1: printf("Enter the item you want to push : ");
                scanf("%d",&item);
                if (!push(item)) printf("Stack full!");
                else printf("Push Successful!");
                break;
        // Pop:
        case 2: item=pop();
                if(item!=-1)
                    printf("The poped item is : %d",item);
                else
                    printf("Stack is Empty");
                break;
        // isFull:
        case 3: if(isFull()) printf("Stack is full!");
                else printf("Stack is not full!");
                break;
        // isEmpty:
        case 4: if(isEmpty()) printf("Stack is empty!");
                else printf("Stack is not empty!");
                break;
        // Peek:
        case 5: item=peek();
                if(item!=-1)
                    printf("The top item is : %d",item);
                else
                    printf("Stack is Empty");
                break;
        // Exit:
        case 6: printf("Exited successfully!"); 
                exit(0); 
                break;
        // Invalid choice:
        default:printf("Invalid choice! Try again.");
            break;
        }
        printf("\n");
    }
    return 0;
}