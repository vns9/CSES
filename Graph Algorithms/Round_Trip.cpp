#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;
 
bool found=false;
vector<ll> parent;
ll cystart=-1;
ll cyend=-1;
 
void dfs(ll i, ll par, map<ll, vector<ll>>& edge, vector<ll>& visited){
    if(found) return;
    visited[i]=1;
    for(auto neib: edge[i]){
        if(found) break;
        if(neib==par) continue;
        if(visited[neib]==1){
            cystart=neib; cyend=i;
            found=true;
            return;
        }
        if(visited[neib]==0){
            parent[neib]=i;
            dfs(neib,parent[neib],edge,visited);
        }
    }
}
 
int main(){
    ll n,m,a,b; cin>>n; cin>>m;
    map<ll, vector<ll>> edge;
    for(ll i=0;i<m;i++){
        cin>>a; cin>>b;
        if(edge.find(a-1)==edge.end()){
            vector<ll> tmp;
            edge[a-1]=tmp;
        }
        if(edge.find(b-1)==edge.end()){
            vector<ll> tmp;
            edge[b-1]=tmp;
        }
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    vector<ll> visited(n,0); 
    for(ll i=0;i<n;i++) parent.push_back(-1);
    for(ll i=0;i<n;i++){
        if(visited[i]==0) dfs(i, parent[i], edge, visited);
    }
    if(!found){
        cout<<"IMPOSSIBLE"; return 0;
    }
    vector<ll> ans;
    
    ll i = cyend;
    ans.push_back(cystart+1);
    while(true) {
        if(i==-1) break;
        ans.push_back(i+1);
        i = parent[i];
        if(i == cystart) {
            ans.push_back(i+1);
            break;
        }
    }
    
    cout<<ans.size()<<endl;    
    for(auto node: ans) cout<<node<<" ";
}