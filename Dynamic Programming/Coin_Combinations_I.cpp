#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x; cin>>n; cin>>x;
    ll modn=1e9+7;
    vector<ll> coin(n);
    for(ll i=0;i<n;i++) cin>>coin[i];
    vector<ll> sum(x+1,0);
    sum[0]=1;
    for(ll i=1;i<=x;i++){
        for(ll j=0;j<n;j++){
            if(i>=coin[j]){
                sum[i]+=(sum[i-coin[j]]%modn);
            }
        }
        sum[i]=sum[i]%modn;
    }
    cout<<sum[x];
}