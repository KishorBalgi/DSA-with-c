#include<iostream>
#include<time.h>
using namespace std;

// 📌 Print Array Function:
void printArr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// 📌 Swap Function:
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

// 📌 Partitioning Function:
int partition(int *a,int l,int h){
    int pivot=a[l];
    int i=l,j=h;

    do{
        // Find element greater than pivot:
        do{
            i++;
        }while(a[i]<=pivot);

        // Find element less than or equal to pivot:
        do{
            j--;
        }while(a[j]>pivot);

        // Swap the smaller and greater element if i<j:
        if(i<j)
            swap(&a[i],&a[j]);

    }while(i<j);
    swap(&a[l],&a[j]);
    return j;
}

// 📌 Quick Sort Function:
void QuickSort(int *a,int l,int h){
    if(l<h){
        int j=partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

int main(){
    clock_t start,end;
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int a[n];
    // 📌 Manual Input:
    // cout<<"Enter the array elements : ";
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // 📌 Random Input:
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
    }
    cout<<"Before Sorting :"<<endl;
    printArr(a,n);
    start=clock();
    // Delay:
    for(int i=0;i<10000;i++)
        for(int j=0;j<10000;j++);
    QuickSort(a,0,n);
    end=clock();
    cout<<"After Sorting :"<<endl;
    printArr(a,n);

    // Execution time:
    double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Execution Time : "<<time_taken<<endl;
}