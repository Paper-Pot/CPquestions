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

int findPages(int *arr, int size, int students){
    int sum = 0;
    for(int i=0;i<size;i++) sum+=arr[i];

    int start = 0,end = sum;
    int mid = start + (end-start)/2;
    int ans = 0;

    while(start<=end){
        if(isPossible(arr,size,students,mid)){
            ans = mid;
            end = mid-1;
        }else start = mid+1;
        mid = start + (end-start)/2;
    }
    return ans;
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
