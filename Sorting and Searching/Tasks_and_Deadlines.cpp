#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,temp1,temp2; cin>>n;
    vector<pair<ll,ll>> task;
    for(ll i=0;i<n;i++){
        cin>>temp1; cin>>temp2;
        task.push_back(make_pair(temp1,temp2));
    }
    sort(task.begin(),task.end());
    ll rew=0, currstart=0;
    for(ll i=0;i<n;i++){
        rew+=task[i].second-(currstart+task[i].first);
        currstart+=task[i].first;
    }
    cout<<rew;
}