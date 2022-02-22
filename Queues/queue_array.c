// 📌Headers:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 📌Globals:
#define SIZE 20
int q[SIZE];
int front=0;
int rear=-1;

// 📌Enqueue:
bool enqueue(int data){
    if(SIZE==rear+1) return false;
    q[++rear]=data;
    return true;
}

// 📌Dequeue:
bool dequeue(int* pData){
    if(rear==-1 || front>rear) return false;
    *pData=q[front++];
    return true;
}

// 📌Front:
bool queueFront(int* pData){
    if(rear==-1 || front>rear) return false;
    *pData=q[front];
    return true;
}

// 📌Rear:
bool queueRear(int* pData){
    if(rear==-1 || front>rear) return false;
    *pData=q[rear];
    return true;
}

// 📌isEmpty:
bool isEmpty(){
    // printf("%d",rear);
    // printf("%d",front);
    if(rear==-1 || front>rear) return true;
    return false;
} 

// 📌isFull:
bool isFull(){
    if(SIZE==rear+1) return true;
    return false;
} 
// 📌Display queue:
void displayQueue(){
    int i;
    if(isEmpty()) {printf("\nQueue is empty\n");return;}
    for(i=front;i<=rear;i++){
        printf("%d ",q[i]);
    }
    return;
}

// 📌Main function:
int main(){
    int choice,data;
    while (1)
    {
        printf("\nQueue options :\n1.Display Queue\n2.Enqueue\n3.Dequeue\n4.Front\n5.Rear\n6.isEmpty\n7.isFul\n8.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            // Display Queue:
            case 1: displayQueue();
                    break;
            // Enqueue:
            case 2: printf("Enter the number yor want to insert : ");
                    scanf("%d",&data);
                    if(enqueue(data)) printf("\nSuccessfully inserted.\n");
                    else printf("\nCould not insert in queue.\n");
                    break;
            // Dequeue:
            case 3: if(dequeue(&data)) printf("\nThe dequeued item is : %d\n",data);
                    else printf("\nQueue is empty.\n");
                    break;
            // Front:
            case 4: if(queueFront(&data)) printf("\nThe front item is : %d\n",data);
                    else printf("\nQueue is empty.\n");
                    break;
            // Rear:
            case 5: if(queueRear(&data)) printf("\nThe Rear item is : %d\n",data);
                    else printf("\nQueue is empty.\n");
                    break;
            // isEmpty:
            case 6: if(isEmpty())printf("\nQueue is empty.\n");
                    else printf("\nQueue is not empty.\n");
                    break;
            // isFull:
            case 7: if(isFull())printf("\nQueue is full.\n");
                    else printf("\nQueue is not full.\n");
                    break;
            // Exit:
            case 8: printf("\nExited successfully!\n");
                    exit(0);
                    break;
            // Invalid choice: 
            default:printf("\nInvalid choice! Please try again.\n");
                    break;
        }
    }
    return 0;
}