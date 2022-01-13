#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    ll curr=1;
    ll maxc=1;
    char c=s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]==c){
            curr+=1;
            maxc=max(maxc, curr);
        }
        else{
            curr=1;
            c=s[i];
        }
    }
    cout<<maxc;
}