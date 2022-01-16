#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

void dfs(ll i, vector<ll>& visited, map<ll, vector<ll>>& road){
    visited[i]=1;
    for(ll neighbour: road[i]){
        if(visited[neighbour]==0) dfs(neighbour,visited,road);
    }
    visited[i]=2;
}

int main(){
    ll n,m,a,b; cin>>n; cin>>m; 
    map<ll, vector<ll>> road;
    for(ll i=0;i<m;i++){
        cin>>a; cin>>b;
        if(road.find(a-1)==road.end()){
            vector<ll> tmp;
            road[a-1]=tmp;
        }
        if(road.find(b-1)==road.end()){
            vector<ll> tmp;
            road[b-1]=tmp;
        }
        road[a-1].push_back(b-1);
        road[b-1].push_back(a-1);
    }
    vector<ll>visited(n,0);
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        if(visited[i]==0){
            ans.push_back(i);
            dfs(i,visited,road);
        }
    }
    if(ans.size()>1){
        cout<<ans.size()-1<<"\n";
        for(ll i=0;i<ans.size()-1;i++){
            cout<<ans[i]+1<<" "<<ans[i+1]+1<<"\n";
        }
        return 0;
    }
    cout<<0; return 0;
}