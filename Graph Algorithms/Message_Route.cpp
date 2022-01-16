#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n,m,a,b; cin>>n; cin>>m; 
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
    vector<ll> visited(n,-1);
    vector<ll> frm(n,-1);
    queue<ll> bfsq;
    bool found=false;
    bfsq.push(0); visited[0]=1;
    while(!bfsq.empty()){
        ll vertex=bfsq.front();
        bfsq.pop();
        for(auto neib: edges[vertex]){
            if(visited[neib]==-1){
                bfsq.push(neib);
                visited[neib]=1;
                frm[neib]=vertex;
            }
        }
    }
    if(frm[n-1]==-1){
        cout<<"IMPOSSIBLE"; return 0;
    }
    vector<ll> path; ll curr=n-1;
    while(curr!=0){
        path.push_back(curr+1);
        curr = frm[curr];
    }
    cout<<path.size()+1<<"\n";
    reverse(path.begin(),path.end());
    cout<<"1"<<" ";
    for(auto node: path){
        cout<<node<<" ";
    }
}