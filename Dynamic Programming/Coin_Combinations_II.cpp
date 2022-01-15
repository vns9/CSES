#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x; cin>>n; cin>>x;
    ll modn=1e9+7;
    vector<ll> coin(n);
    for(ll i=0;i<n;i++) cin>>coin[i];
    vector<ll> sum(x+1);
    sum[0]=1;
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=x;j++){
            if(j>=coin[i]){
                sum[j]+=sum[j-coin[i]]%modn;
                sum[j]=sum[j]%modn;
            }
        }
    }
    cout<<sum.back();
}