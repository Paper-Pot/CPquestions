#include <iostream>
using namespace std;

bool isPossible(int* arr,int size,int students, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for(int i=0;i<size;i++){
        if(pageSum+arr[i] <= mid) pageSum+=arr[i];
        else{
            studentCount++;
            if(studentCount > students || arr[i]>mid) return false;
            pageSum = arr[i];
        }
    }
    return true;
}

int findMin(int *arr,int n,int m,int start,int end,int *ans){
    if(start>end) return *ans;
    int mid = start+(end-start)/2;
    if(isPossible(arr,n,m,mid)){
        *ans = mid;
        findMin(arr,n,m,start,mid-1,ans);
    }else findMin(arr,n,m,mid+1,end,ans);
    return *ans;
}
int findPages(int *arr,int n,int m){
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    int start = 0;
    int ans = -1;
    return findMin(arr,n,m,start,sum,&ans);
}
int main(){
    int length,students;
    cout<<"Enter the number of books"<<endl;
    cin>> length;
    int* arr = (int*)malloc(length*sizeof(int));
    cout<<"Enter the pages for each book"<<endl;
    for(int i=0;i<length;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of students to divide books to"<<endl;
    cin>>students;
    cout<<"Maximum number of books that can be alloted to a student is "<<findPages(arr,length,students);
}
