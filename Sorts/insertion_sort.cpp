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


// 📌Insertion Sort Function:
void InsertionSort(int *a,int n){
    int x,i,j;
    for(i=1;i<n;i++){
        j=i-1;
        x=a[i];
        while(a[j]>x && j>-1){
            // Shift:
            a[j+1]=a[j];
            j--;
        }
        // Insert:
        a[j+1]=x;
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
    InsertionSort(a,n);
    end=clock();
    cout<<"After Sorting :"<<endl;
    printArr(a,n);

    // Execution time:
    double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Execution Time : "<<time_taken<<endl;
}