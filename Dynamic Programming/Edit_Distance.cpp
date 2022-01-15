#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

string s1,s2;

ll helper(ll i, ll j, vector<vector<ll>>& dp){
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i-1][j-1]==-1){
        if(s1[s1.length()-i] == s2[s2.length()-j]){
            dp[i-1][j-1] = min(helper(i-1,j,dp)+1, helper(i,j-1,dp)+1);
            dp[i-1][j-1] = min(dp[i-1][j-1], helper(i-1,j-1,dp));
        }
        else{
            dp[i-1][j-1] = min(helper(i-1,j,dp)+1, helper(i,j-1,dp)+1);
            dp[i-1][j-1] = min(dp[i-1][j-1], helper(i-1,j-1,dp)+1);
        }
    }
    return dp[i-1][j-1];
}

int main(){
    cin>>s1; cin>>s2;
    vector<vector<ll>> dp(s1.length(), vector<ll>(s2.length(),-1));
    cout<<helper(s1.length(),s2.length(),dp);
}