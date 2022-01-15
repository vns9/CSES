#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x; cin>>n; cin>>x;
    vector<ll> coin(n);
    for(ll i=0;i<n;i++) cin>>coin[i];
    vector<ll> sum(x+1,-1);
    sum[0]=0;
    for(ll i=1;i<=x;i++){
        ll ans=LONG_MAX;
        bool check=false;
        for(ll j=0;j<n;j++){
            if(i>=coin[j]){
                if(sum[i-coin[j]]!=-1){
                    check=true;
                    ans=min(ans,sum[i-coin[j]]+1);
                }
            }
        }
        if(check) sum[i]=ans;
    }
    cout<<sum[x];
}