#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

ll help(ll i, ll j, vector<vector<char>>& grid, vector<vector<ll>>& dp){
    ll ans=0;
    if(grid[i][j]!='.') return 0;
    if(dp[i][j]==-1){
        if(i>=1) if(grid[i-1][j]=='.') ans+=(help(i-1,j,grid,dp)%modn);
        if(j>=1) if(grid[i][j-1]=='.') ans+=(help(i,j-1,grid,dp)%modn);
        dp[i][j]=ans%modn;
    }
    return dp[i][j];
}
int main(){
    ll n; cin>>n; string s;
    vector<vector<char>> grid;
    vector<vector<ll>> dp;
    for(ll i=0;i<n;i++){
        vector<char> temp(n); cin>>s;
        for(ll j=0;j<n;j++) temp[j]=s[j];
        grid.push_back(temp);
        vector<ll> v(n,-1); dp.push_back(v);
    }
    dp[0][0]=1;
    cout<<help(n-1,n-1,grid,dp);
}