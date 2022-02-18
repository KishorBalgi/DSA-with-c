// Headers:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Data node structure definition:
typedef struct node{
    int data;
    struct node* next;
}NODE;

// Head node structure definition:
typedef struct{
    int count;
    NODE* head;
    NODE* preLoc;
    NODE* rear;
}LIST;

// Create List:
LIST* createList(){
    LIST* list;
    list=(LIST*)malloc(sizeof(LIST));
    if(list){
        list->count=0;
        list->head=NULL;
        // list->preLoc=NULL;
        list->rear=NULL;
    }
    return list;
}
// Create data node:
NODE* createNode(){
    NODE* pNew;
    pNew=(NODE*)malloc(sizeof(NODE));
    pNew->data=0;
    pNew->next=NULL;
    return pNew;
}
// isEmpty:
bool isEmpty(LIST* pList){
    if(pList->head==NULL) return true;
    return false;
}
// Insert at front:
bool insertAtFront(LIST* pList,int data){
    NODE* pNew;
    if(!(pNew=createNode())) return false;
    pNew->data=data;
    if(pList->head==NULL){
        pList->head=pNew;
        pList->rear=pNew;
    }else{
        pNew->next=pList->head;
        pList->head=pNew;
    }
    pList->count=pList->count+1;
    return true;
}
// Insert at end:
bool insertAtEnd(LIST* pList,int data){
    NODE* pNew;
    if(!(pNew=createNode())) return false;
    pNew->data=data;
    if(pList->head==NULL){
        pList->head=pNew;
        pList->rear=pNew;
    }else{
        // pList->preLoc=pList->rear;
        pList->rear->next=pNew;
        pList->rear=pNew;
    }
    pList->count=pList->count+1;
    return true;
}
// Delete at end:
// bool deleteAtEnd(LIST *pList){
//     if(isEmpty(pList)) return false;
//     if(pList->count==1) {
//         pList->head=NULL;
//         pList->rear=NULL;
//     }else{
//         pList->preLoc->next=NULL;
//         pList->rear=pList->preLoc;
//     }
//     pList->head=pList->head->next;
//     pList->count=pList->count-1;
//     return true;
// }
// Delete at front:
bool deleteAtFront(LIST *pList){
    if(isEmpty(pList)) return false;
    pList->head=pList->head->next;
    pList->count=pList->count-1;
    return true;
}
// Count:
int count(LIST* pList){
    return pList->count;
}
// Display list:
void displayList(LIST* pList){
    NODE* tptr=pList->head;
    if(tptr==NULL) {
        printf("List is empty!"); 
        return;
    }
    printf("\n");
    while(tptr!=NULL){
        printf("%d",tptr->data);
        printf(" ");
        tptr=tptr->next;
    }
    printf("\n");
    return;
}
int main(){
    int choice,data;
    LIST* list;
    printf("\nList Options:\n1.Create List\n2.Display List\n3.Insert at front\n4.Insert at end\n5.Insert in order\n6.Delete at front\n7.Delete at end\n8.Display count\n0.EXIT"); 
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            // Creat a list:
            case 1: list=createList();
                    if(!list) printf("\nCould not create a new list!\n");
                    else printf("\nSuccessfully created a new list!\n ");
                    break;
            // Display list:
            case 2: displayList(list);
                    break;
            // Insert at front:
            case 3: printf("Enter the number you want to insert at front: ");
                    scanf("%d",&data);
                    if(insertAtFront(list,data)) printf("\nSuccessfully inserted at front!\n ");
                    else printf("\nCould not insert at front!\n ");
                    break;
            // Insert at end:
            case 4: printf("Enter the number you want to insert at end: ");
                    scanf("%d",&data);
                    if(insertAtEnd(list,data)) printf("\nSuccessfully inserted at end!\n ");
                    else printf("\nCould not insert at end!\n ");
                    break;
            // Insert in order:
            case 5: break;
            // Delete at front:
            case 6: if(deleteAtFront(list))  printf("\nSuccessfully deleted at front!\n ");
                    else printf("\nList empty!\n");
                    break;
            // Delete at end:
            case 7:break;
            // Count:
            case 8: printf("%d",count(list));
                    break;
            // Exit:
            case 0: printf("\nExited successfully!\n");
                    exit(0);
                    break;
            // Invalid choice:
            default: printf("\nInvalid choice! Please try again.\n");
                    break;
        }
    }
    return 0;
}