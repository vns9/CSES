#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,t; cin>>n; cin>>t;
    vector<ll>v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll lo=1, hi=1e18; 
    while(lo<=hi){
        ll mid = (hi+lo)/2;
        ll cnt=0;
        for(ll i=0;i<n;i++){
            cnt+=(mid/v[i]);
            if(cnt>=t) break;
        }
        if(cnt<t) lo=mid+1;
        else hi=mid-1;
    }
    cout<<lo;
}