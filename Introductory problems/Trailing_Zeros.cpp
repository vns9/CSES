#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,k=5;
    cin>>n;
    ll cnt=0;
    while(floor(n/k)!=0){
        cnt+=floor(n/k);
        k*=5;   
    }
    cout<<cnt;
}