#include<iostream>
#include<stdio.h>
using namespace std;

int FindMax(int* arr,int n){
    int* ptr1;
    int* ptr2;
    int numMax,i=0;
    ptr1=arr;
    ptr2=arr+(n-1);
    while(i<n){
        if(*ptr2>*ptr1) {
            numMax=*ptr2;
            ptr1++;
        }
        else{ 
            numMax=*ptr1;
            ptr2--;
        }
        i++;
    }
    return numMax;
}
int main(){
    int n;
    cin>>n;
    int* arr = (int*)malloc(sizeof(int));
    for(int i=0;i<n;i++) cin>>*(arr+i);
    cout<<FindMax(arr,n);
    free(arr);
}