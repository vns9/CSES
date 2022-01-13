#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n,temp; cin>>n;
    vector<pair<ll,ll>>v;
    ll ans=1;
    for(ll i=0;i<n;i++){
        cin>>temp; v.push_back(make_pair(temp,i));
    }
    sort(v.begin(),v.end());
    ll currpos=v[0].second;
    for(ll i=1;i<n;i++){
        if(v[i].second<currpos){
            ans++;
        }
        currpos=v[i].second;
    }
    cout<<ans;
}