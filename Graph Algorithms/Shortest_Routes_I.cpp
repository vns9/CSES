#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n,m; cin>>n; cin>>m;
    map<ll, map<ll,ll>> adj;
    for(ll i=1;i<=m;i++){
        ll a,b,dist;
        cin>>a; cin>>b; cin>>dist;
        if(adj.find(a)==adj.end()){
            adj[a][b]=dist; continue;
        }
        if(adj[a].find(b)==adj[a].end()){
            adj[a][b]=dist; continue;
        }
        adj[a][b]=min(adj[a][b],dist);
    }
    vector<ll> distance(n+1, LONG_MAX); distance[1]=0;
    vector<bool> done(n+1,false);
    set<pair<ll,ll>> process; process.insert(make_pair(0,1));
    while(process.size()!=0){
        auto curr = *process.begin();
        process.erase(process.begin());
        if(done[curr.second]) continue;
        done[curr.second]=true;
        for(auto kv: adj[curr.second]){
            distance[kv.first] = min(distance[kv.first], distance[curr.second]+kv.second);
            process.insert(make_pair(distance[kv.first],kv.first));
        }
    }
    for(ll i=1;i<=n;i++) cout<<distance[i]<<" ";
}