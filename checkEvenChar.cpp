/*
You are given a string SS with length NN. You may perform the following operation any number of times: choose a non-empty substring of SS (possibly the whole string SS) such that each character occurs an even number
of times in this substring and erase this substring from SS. (The parts of SS before and after the erased substring are concatenated and the next operation is performed on this shorter string.)

For example, from the string "acabbad", we can erase the highlighted substring "abba", since each character occurs an even number of times in this substring. After this operation, the remaining string is "acd".

Is it possible to erase the whole string using one or more operations?

Note: A string BB is a substring of a string AA if BB can be obtained from AA by deleting several (possibly none or all) characters from the beginning and several (possibly none or all) characters from the end.

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first line of each test case contains a single integer NN.
The second line contains a single string SS with length NN.
Output
For each test case, print a single line containing the string "YES" if it is possible to erase the whole string or "NO" otherwise (without quotes).

Constraints
1 ≤ T ≤ 200
1 ≤ N ≤ 1000
S contains only lowercase English letters
*/

#include <iostream>
#include <stdio.h>
using namespace std;

bool checkZero(int* arr){
    for(int i=0;i<26;i++){
        if(arr[i]!=0) return false;
    }
    return true;
}

void solution(){
    int n;
    cin>>n;
    char* s = (char*)malloc(n*sizeof(char));

    for(int i=0;i<n;i++) cin>>s[i];
    int arr[26]={0};

    for(int i=0;i<n;i++){

        int g=(int)s[i]-97;

        if(arr[g]==0) arr[g]+=1;
        else if(arr[g]==1) arr[g]-=1;
    }
    
    if(checkZero(arr)) cout<<"YES\n";
    else cout<<"NO\n";

    free(s);
}
int main() {
	int t;
	cin>>t;
	while(t--) solution();
	return 0;
}
/* Explain:
    we take input the length of string needed to be checked, then string itself
    then we create a reference array and set its to size 26 due the given constrains
    we create the array as a lookup table so that we can determine each letter's frequency
    now we create another int vairable to get the index where we wnat to increment the val or decrement val

    eg: if s[i] = a; ASCII for a is 97 so we substract 97 to get the index i.e. 0 and hence incrementing or
        decrement val at index 0 by 1; then we check if all elements in array are zero we print YES else NO.
	
  Time Complexity: O(n)
*/
