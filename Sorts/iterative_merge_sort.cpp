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

// 📌 Merge Function:
void Merge(int *a,int l,int m,int h){
    int b[h-l+1];
    int i=l,j=m+1,k=0;
    while(i<=m && j<=h){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        if(a[j]<a[i]){
            b[k++]=a[j++];
        }
    }
    while(i<=m){
        b[k++]=a[i++];
    }
    while(j<=h){
        b[k++]=a[j++];
    }
    for(i=l,j=0;j<k;i++,j++){
        a[i]=b[j];
    }
}

// 📌 Merge Sort Function:
void MergeSort(int *a,int n){
    int p,i,l,m,h;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            m=(l+h)/2;
            Merge(a,l,m,h);
            printArr(a,n);
        }
    }
    if(p/2<n){
        Merge(a,0,p/2-1,n);
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
    MergeSort(a,n);
    end=clock();
    cout<<"After Sorting :"<<endl;
    printArr(a,n);

    // Execution time:
    double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Execution Time : "<<time_taken<<endl;
}