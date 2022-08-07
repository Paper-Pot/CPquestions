#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin>>n;                                                     // takes length of string input
    int size=n;
    if(n&1==1) size-=1;                                         // if n is odd
    string str;
    cin>>str;                                                   // string to be encoded
    for(int i=0;i<size;i+=2) swap(str[i],str[i+1]);             // swaps adjacent characters
    for(int i=0;i<n;i++) cout<<(char)(219-str[i]);              // changes each char's ascii value by 219
    cout<<endl;
}
int main() {
	int t;                                                      // number of test cases
	cin>>t;
	while(t--) solution();
	return 0;
}