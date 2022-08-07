#include<iostream>
#include<stdio.h>
using namespace std;

int calc(int *a,int *b,int n){                          // calculates the winners Points
    int max=0,count=0;
    for(int i=0;i<n;i++){
        count=*(a+i)*5 + *(b+i)*2;                      // winPoints*5 + drawPoints*2
        if(count>max) max=count;
    }
    return max;
}
int main(){
    int n;
    cin>>n;                                             // number of players
    int* winnsPerPlayer=(int*)malloc(n*sizeof(int)); 
    for(int i=0;i<n;i++) cin>>winnsPerPlayer[i];        //  winns per player
    int* drawsPerPlayer=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) cin>>drawsPerPlayer[i];        // draws per player
    cout<<calc(winnsPerPlayer,drawsPerPlayer,n);
    free(winnsPerPlayer);
    free(drawsPerPlayer);
}