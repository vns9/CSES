#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a;
    cin>>a;
    while(a!=1){
        cout<<a<<" ";
        if(a%2==0) a=a/2;
        else a=(a*3)+1;
    }
    cout<<a;
}