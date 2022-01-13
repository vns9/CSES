#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sort_pred {
    bool operator()(const std::pair<ll,ll> &left, const std::pair<ll,ll> &right) {
        return left.second < right.second;
    }
};

int main(){
    ll n; cin>>n;
    if(n==1){
        cout<<"1";
        return 0;
    }
    ll temp1,temp2;
    vector<pair<ll,ll>> time;
    for(ll i=0;i<n;i++){
        cin>>temp1; cin>>temp2;
        time.push_back(make_pair(temp1,temp2));
    }
    ll ans=1;
    sort(time.begin(),time.end(), sort_pred());
    ll currend=time[0].second;
    for(ll i=1;i<n;i++){
        if(time[i].first>=currend){
            currend=time[i].second;
            ans++;
        }
    }
    cout<<ans;
}