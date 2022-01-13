#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n; cin>>n;
    map<ll,ll> curr;
    ll ans=1;
    ll temp,ptr1=1;
    for(ll i=1;i<=n;i++){
        cin>>temp;
        if(curr[temp]){
            ans=max(ans,i-ptr1);
            ptr1=max(ptr1, curr[temp]+1);
            curr[temp]=i;
        }
        else{
            ans=max(ans,i+1-ptr1);
            curr[temp]=i;
        }
    }
    cout<<ans;
}