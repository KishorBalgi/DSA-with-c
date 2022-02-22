// 📌Headers:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 📌Structure defination for data node:
typedef struct node{
    int data;
    struct node* next;
}NODE;

// 📌Structure defination for head node:
typedef struct{
    struct node* front;
    int count;
    struct node* rear;
}QUEUE;

// 📌Create a queue:
QUEUE* createQueue(){
    QUEUE* pNew;
    pNew=(QUEUE*)malloc(sizeof(QUEUE));
    if(pNew){
        pNew->front=NULL;
        pNew->count=0;
        pNew->rear=NULL;
    }
    return pNew;
}

// 📌Create a data node:
NODE* createDataNode(){
    NODE* pNew;
    pNew=(NODE*)malloc(sizeof(NODE));
    pNew->data=0;
    pNew->next=NULL;
    return pNew;
}

// 📌Enqueue:
bool enqueue(QUEUE* pQueue,int data){
    NODE* pNew;
    if(!(pNew=createDataNode())) return false;
    pNew->data=data;
    if(pQueue->front==NULL){
        pQueue->front=pNew;
        pQueue->rear=pNew;
    }
    else{
        pQueue->rear->next=pNew;
        pQueue->rear=pNew;
    }
    pQueue->count= pQueue->count +1;
    return true;
}

// 📌Dequeue:
bool dequeue(QUEUE* pQueue,int* pData){
    if(pQueue->count==0) return false;
    *pData=pQueue->front->data;
    pQueue->front=pQueue->front->next;
    pQueue->count= pQueue->count-1;
    return true;
}

// 📌Display queue:
void displayQueue(QUEUE* pQueue){
    NODE* tptr;
    if(pQueue->count==0){printf("\nQueue is empty.\n"); return;}
    tptr=pQueue->front;
    printf("\n");
    while(tptr!=NULL){
        printf("%d ",tptr->data);
        tptr=tptr->next;
    }
    printf("\n");
    return;
}

// 📌isEmpty:
bool isEmpty(QUEUE* pQueue){
    if(pQueue->count==0) return true;
    return false;
}

// 📌isFull:
bool isFull(QUEUE* pQueue){
    NODE* pNew;
    if(!(pNew=(NODE*)malloc(sizeof(NODE)))) return true;
    free(pNew);
    return false;
}

// 📌Front:
bool front(QUEUE* pQueue,int* pData){
    if(isEmpty(pQueue)) return false;
    *pData=pQueue->front->data;
    return true;
}

// 📌Rear:
bool rear(QUEUE* pQueue,int* pData){
    if(isEmpty(pQueue)) return false;
    *pData=pQueue->rear->data;
    return true;
}

// 📌Count:
int count(QUEUE* pQueue){
    return pQueue->count;
}

// 📌Destroy queue:
bool destroyQueue(QUEUE* pQueue){
    NODE* tptr=pQueue->front;
    NODE* p;
    if(!isEmpty(pQueue)){
        while (tptr!=NULL)
        {
            p=tptr->next;
            free(tptr);
            tptr=p;
        }
    }
    free(pQueue);
    return true;
}

// 📌Main function:
int main(){
    int choice,data;
    QUEUE* queue;
    while (1)
    {
        printf("\nQueue options :\n1.Create Queue\n2.Display Queue\n3.Enqueue\n4.Dequeue\n5.Front\n6.Rear\n7.isEmpty\n8.isFull\n9.Count\n10.Destroy Queue\n11.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            // Create Queue:
            case 1: if(queue=createQueue()) printf("\nSuccessfully created a new Queue.\n");
                    else printf("\nCould not created a new Queue.\n");
                    break;
            // Display Queue:
            case 2: displayQueue(queue);
                    break;
            // Enqueue:
            case 3: printf("Enter the number yor want to insert : ");
                    scanf("%d",&data);
                    if(enqueue(queue,data)) printf("\nSuccessfully inserted.\n");
                    else printf("\nCould not insert in queue.\n");
                    break;
            // Dequeue:
            case 4: if(dequeue(queue,&data)) printf("\nThe dequeued item is : %d\n",data);
                    else printf("\nQueue is empty.\n");
                    break;
            // Front:
            case 5: if(front(queue,&data)) printf("\nThe front item is : %d\n",data);
                    else printf("\nQueue is empty.\n");
                    break;
                    break;
            // Rear:
            case 6: if(rear(queue,&data)) printf("\nThe Rear item is : %d\n",data);
                    else printf("\nQueue is empty.\n");
                    break;
                    break;
            // isEmpty:
            case 7: if(isEmpty(queue))printf("\nQueue is empty.\n");
                    else printf("\nQueue is not empty.\n");
                    break;
            // isFull:
            case 8: if(isFull(queue))printf("\nQueue is full.\n");
                    else printf("\nQueue is not full.\n");
                    break;
            // Count:
            case 9: printf("\nQueue count is : %d\n",count(queue));
                    break;
            // Destroy Queue:
            case 10: if(destroyQueue(queue)) printf("\nQueue destroyed successfully.\n");
                    else printf("\nQueue destroyed unsuccessfully.\n");
                    break;
            // Exit:
            case 11: printf("\nExited successfully!\n");
                    exit(0);
                    break;
            // Invalid choice: 
            default:printf("\nInvalid choice! Please try again.\n");
                    break;
        }
    }
    return 0;
}