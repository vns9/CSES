#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    ll temp1,temp2;
    vector<pair<ll,ll>> time;
    for(ll i=0;i<n;i++){
        cin>>temp1; cin>>temp2;
        time.push_back(make_pair(temp1,1));
        time.push_back(make_pair(temp2,-1));
    }
    ll ans=LONG_MIN;
    ll curr=0;
    sort(time.begin(),time.end());
    for(ll i=0;i<2*n;i++){
        if(time[i].second==1){
            curr++;
            ans=max(ans,curr);
        }
        else{
            curr--;
        }
    }
    cout<<ans;
}