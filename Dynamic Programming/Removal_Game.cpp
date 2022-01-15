#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

ll helper(ll i, ll j, vector<vector<ll>>& dp, vector<ll> & v){
    if(i>j) return 0;
    ll val=LONG_MIN;
    if(dp[i][j]==-1){
        val = max(val, v[i]+min(helper(i+2,j,dp,v), helper(i+1,j-1,dp,v)));
        val = max(val, v[j]+min(helper(i,j-2,dp,v), helper(i+1,j-1,dp,v)));
        dp[i][j]=val;
    }
    return dp[i][j];
}

int main(){
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    vector<vector<ll>> dp(n, vector<ll>(n,-1));
    cout<<helper(0,n-1,dp,v);
}