// 📌Headers:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 📌Data node structure defination:
typedef struct node
{
    int data;
    struct node* next;
}NODE;

// 📌Head node structure defination:
typedef struct {
    int count;
    NODE* top;
}STACK;

// 📌Create stack:
STACK* createStack(){
    STACK* pNew;
    pNew=(STACK*)malloc(sizeof(STACK));
    if(pNew){
        pNew->count=0;
        pNew->top=NULL;
    }
    return pNew;
}

// 📌Create new data node:
NODE* createNewNode(){
    NODE* pNew;
    pNew=(NODE*)malloc(sizeof(NODE));
    return pNew;
}

// 📌Push:
bool push(STACK* pStack,int data){
    NODE* newNode;
    if(!(newNode=createNewNode())) return false;
    newNode->data=data;
    newNode->next=pStack->top;
    pStack->top=newNode;
    pStack->count=pStack->count+1;
    return true;
}

// 📌Pop:
bool pop(STACK* pStack,int* pData){
    if(pStack->top==NULL) return false;
    *pData=pStack->top->data;
    pStack->top=pStack->top->next;
    pStack->count=pStack->count-1;
    return true;
}

// 📌Peek:
bool peek(STACK* pStack,int* pData){
    if(pStack->top==NULL) return false;
    *pData=pStack->top->data;
    return true;
}
// 📌Is Empty:
bool isEmpty(STACK* pStack){
    if(pStack->top==NULL){
        printf("\nStack is empty!\n");
        return true;
    }
    printf("\nStack is not empty!\n");
    return false;
}
// 📌Is Full:
bool isFull(STACK* pStack){
    NODE* newNode;
    if(!(newNode=createNewNode())) {
        printf("\nStack is full!\n");
        return true;
    }
    free(newNode);
    printf("\nStack is not full!\n");
    return false;
}
// 📌Count:
void count(STACK* pStack){
    if(pStack->top==NULL) {printf("\nStack is empty\n"); return;}
    printf("\n%d\n",pStack->count);
    return;
}
// 📌Display stack:
void displayStack(STACK* pStack){
    if(pStack->top==NULL) {printf("Stack is empty"); return;}
    NODE* tptr=pStack->top;
    printf("\n");
    while (tptr!=NULL)
    {
        printf("%d\n",tptr->data);
        tptr=tptr->next;
    }
    printf("\n");
    return;
}
// 📌Destroy stack:
bool destroyStack(STACK* pStack){
    NODE* tptr=pStack->top;
    NODE* p;
    if(pStack->top!=NULL){
        while (tptr!=NULL){
            p=tptr->next;
            free(tptr);
            tptr=p;
        }
    }
    free(pStack);
    return true;
}
// 📌Main function:
int main(){
    STACK* stack;
    int data,choice;
    while(1){
        printf("\nStack Options :\n1.Create stack\n2.Display stack\n3.Push\n4.Pop\n5.Peek\n6.isEmpty\n7.isFull\n8.Count\n9.Destroy stack\n10.Exit\n");
        printf("Enter Your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        // Create stack
        case 1:if(stack=createStack()) printf("\nSuccessfully created stack!\n");
                else printf("\nCouldnot create stack!\n");
                break;
        // Display stack:
        case 2: displayStack(stack);
                break;
        // Push:
        case 3: printf("Enter the number to be pushed : ");
                scanf("%d",&data);
                if(push(stack,data)) printf("\nuccessfully pushed.\n");
                else printf("\ncould not push into the stack.\n");
                break;
        // Pop:
        case 4: if(pop(stack,&data)) printf("\nPoped item is : %d\n",data);
                else printf("\nStack is empty.\n");
                break;
        // Peek:
        case 5: if(peek(stack,&data)) printf("\nTop item is : %d\n",data);
                else printf("\nStack is empty.\n");
                break;
        // Is empty:
        case 6: isEmpty(stack);
                break;
        // Is full:
        case 7: isFull(stack);
                break;
        // Count:
        case 8:count(stack);
                break;
        // Destroy stack:
        case 9:if(destroyStack(stack)) printf("Stack destroyed successfully.");
                else printf("Could not destroy stack.");
                break;
        // Exit:
        case 10:printf("Exited successfully."); 
                exit(0);
                break;
        // Invalide choice:
        default: printf("Invalid choice. Try again.");
                break;
        }
    }
}