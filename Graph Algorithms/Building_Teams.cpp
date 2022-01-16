#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

bool impossible=false;

void dfs(ll i, ll sno, map<ll, vector<ll>>& edges, vector<ll>& visited, vector<ll>& tgrps){
    visited[i]=1;
    tgrps[i]=sno;
    ll nextgrp;
    if(sno==1) nextgrp=2;
    if(sno==2) nextgrp=1;
    for(auto neib: edges[i]){
        if(visited[neib]==-1){
            dfs(neib,nextgrp,edges,visited,tgrps);
        }
        else if(visited[neib]==1 && tgrps[neib]!=nextgrp){
            impossible=true;
        }
    }
    visited[i]=2;
}
int main(){
    ll n,m,a,b; cin>>n; cin>>m; 
    vector<ll> visited(n,-1);
    vector<ll> tgrps(n,-1);
    map<ll, vector<ll>> edges;
    for(ll i=0;i<m;i++){
        cin>>a; cin>>b;
        if(edges.find(a-1)==edges.end()){
            vector<ll> tmp;
            edges[a-1]=tmp;
        }
        if(edges.find(b-1)==edges.end()){
            vector<ll> tmp;
            edges[b-1]=tmp;
        }
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    for(ll i=0;i<n;i++){
        if(visited[i]==-1){
            dfs(i,1,edges,visited,tgrps);
        }
    }
    if(impossible){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(auto grp: tgrps) cout<<grp<<" ";
}