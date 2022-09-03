#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isSquare(int n){
   if(ceil((double)sqrt(n)) == floor((double)sqrt(n))) return true;
   return false;
}
void findSquare(vector<int> arr,int n){
    for(auto i =arr.begin();i!=arr.end();++i ){
        if(!isSquare(*i)){
            arr.erase(i);
            i--;
        }
    }
    cout<<"The Elements in vector that are perfect squares are\n";
    for(auto it = arr.begin(); it != arr.end(); ++it) cout<< *it<<" ";
}
int main(){
    int n,temp;
    vector<int> arr;
    cout<<"Enter the number of items in vector\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i =0;i<n;i++) {
        cin>>temp;
        arr.push_back(temp);
    }
    findSquare(arr,n);
    
}
