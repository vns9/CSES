#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n,temp; cin>>n;
    vector<ll>v(n);
    ll ans=1;
    for(ll i=0;i<n;i++){
        cin>>temp; v[i]=temp;
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){
        if(v[i]<=ans){
            ans+=v[i];
            continue;
        }
        if(v[i]>ans){
            break;
        }
    }
    cout<<ans;
}