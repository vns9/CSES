#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    if(n<10){
        cout<<1; return 0;
    }
    vector<ll> step(n+1);
    step[0]=0;
    for(ll i=1;i<=9;i++) step[i]=1;
    for(ll i=10;i<=n;i++){
        ll ans=LONG_MAX;
        string s=to_string(i);
        for(char c: s){
            if(c!='0') ans=min(ans, 1+step[i-(c-'1'+1)]);
        }
        step[i]=ans;
    }
    cout<<step.back();
}