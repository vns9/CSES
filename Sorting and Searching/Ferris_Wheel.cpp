#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x; cin>>n>>x;
    ll ans=0;
    vector <ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll f=0, e=n-1;
    while(f<=e){
        if(f==e){
            ans++;
            break;
        }
        if(v[f]+v[e]<=x){
            f++; e--; ans++;
        }
        else{
            e--; ans++;
        }
    }
    cout<<ans;
}