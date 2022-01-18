#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

ll helper(ll i, map<ll,vector<ll>>& adj, vector<ll>& dp){
    if(dp[i]==-1){
        if(adj.find(i)==adj.end()){
            dp[i]=0; return 0;
        }
        if(adj[i].empty()){
            dp[i]=0; return 0;
        }
        else{
            dp[i]=0;
            for(auto reporter: adj[i]){
                dp[i]+=1;
                dp[i]+=helper(reporter,adj,dp);
            }
        }
    }
    return dp[i];
}
int main(){
    ll n; cin>>n;
    map<ll,vector<ll>> adj;
    for(ll i=2;i<=n;i++){
        ll tmp; cin>>tmp;
        if(adj.find(tmp)==adj.end()){
            vector<ll>v; adj[tmp]=v;
        }
        adj[tmp].pb(i);
    }
    vector<ll> dp(n+1,-1);
    helper(1, adj, dp);
    for(ll i=1;i<=n;i++) cout<<dp[i]<<" ";
}