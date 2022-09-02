#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int *stalls,int length, int cows, int mid){
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i=0;i<length;i++){
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount == cows) return true;
            lastPos = stalls[i];
        }
    }
    return false;
}
int findMin(int *stalls,int length,int cows,int start,int end,int *ans){
    if(start>end) return *ans;
    int mid = start+(end-start)/2;
    if(isPossible(stalls,length,cows,mid)){
        *ans = mid;
        findMin(stalls,length,cows,mid+1,end,ans);
    }else findMin(stalls,length,cows,start,mid-1,ans);
    return *ans;
}
int findPages(int *stalls,int length,int cows){
    sort(stalls, stalls+(length-1));
    int maxVal = stalls[length-1];
    int start = 0;
    int ans = -1;
    return findMin(stalls,length,cows,start,maxVal,&ans);
}
int main(){
    int length,cows;
    cout<<"Enter the number of stalls"<<endl;
    cin>> length;
    int* stalls = (int*)malloc(length*sizeof(int));
    cout<<"Enter the position for each stall"<<endl;
    for(int i=0;i<length;i++) cin>>stalls[i];
    cout<<"Enter the number of cows"<<endl;
    cin>>cows;
    cout<<"Maximum number of stalls that cows should be placed apart is "<<findPages(stalls,length,cows);
}
