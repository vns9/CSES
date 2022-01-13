#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long ll;

int main(){
    fio;
    ll n; cin>>n;
    ll ans=LONG_MAX;
    vector<ll> v(n,0);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll tot=0;
    for(ll i=0;i<n;i++) tot+=v[i];
    for(ll i=0;i<(1<<n);i++){
        ll curr=0;
        for(ll j=0;j<n;j++){
            if((1<<j)&i) curr+=v[j];
        }
        ans=min(ans, abs((tot-curr)-curr));
    }
    cout<<ans;
}