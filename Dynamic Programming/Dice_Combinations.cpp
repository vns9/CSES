#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    ll modn = 1e9+7;
    vector<ll> v(n+1,0);
    if(n==1){
        cout<<1; return 0;
    }
    if(n==2){
        cout<<2; return 0;
    }
    v[0]=1; v[1]=1; v[2]=2;
    for(ll i=3; i<=n; i++){
        if(i-1>=0) v[i]+=(v[i-1]%modn);
        if(i-2>=0) v[i]+=(v[i-2]%modn);
        if(i-3>=0) v[i]+=(v[i-3]%modn);
        if(i-4>=0) v[i]+=(v[i-4]%modn);
        if(i-5>=0) v[i]+=(v[i-5]%modn);
        if(i-6>=0) v[i]+=(v[i-6]%modn);
        v[i]=v[i]%modn;
    }
    cout<<v[n];
}