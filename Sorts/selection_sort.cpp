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

// 📌 Selection Sort Function:
void SelectionSort(int *a,int n){
    int min,i,j;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min])
                min=j;
        swap(a[i],a[min]);
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
    SelectionSort(a,n);
    end=clock();
    cout<<"After Sorting :"<<endl;
    printArr(a,n);

    // Execution time:
    double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Execution Time : "<<time_taken<<endl;
}