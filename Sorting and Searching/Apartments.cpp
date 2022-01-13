#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m,k; cin>>n; cin>>m; cin>>k;
    ll ans=0;
    vector<ll> apart(m);
    vector<ll> appl(n);
    ll start=0;
    for(ll i=0;i<n;i++) cin>>appl[i];
    for(ll i=0;i<m;i++) cin>>apart[i];
    sort(appl.begin(),appl.end());
    sort(apart.begin(),apart.end());
    ll apart_ptr=0;
    ll appl_ptr=0;
    while(apart_ptr<m&&appl_ptr<n){
        if(abs(appl[appl_ptr]-apart[apart_ptr])<=k){
            apart_ptr++;
            appl_ptr++;
            ans++;
            continue;
        }
        if(appl[appl_ptr]-apart[apart_ptr]>k){
            apart_ptr++;
            continue;
        } 
        if(apart[apart_ptr]-appl[appl_ptr]>k){
            appl_ptr++;
            continue;
        } 
    }
    // n**2 complexity
    // for(ll i=0;i<m;i++){
    //     if(ans==n) break;
    //     if(apart[m-1]<appl[start]-k || appl[n-1]+k<apart[i]) break;
    //     for(ll j=start;j<n;j++){
    //         if(apart[i]>=(appl[j]-k)&&apart[i]<=(appl[j]+k)){
    //             ans++;
    //             start=j+1;
    //             break;
    //         }
    //     }
    // }
    cout<<ans;
}