#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n; cin>>n;
    ll tot_sum = n*(n+1)/2;
    if(tot_sum%2==1){
        cout<<0; return 0;
    }
    tot_sum/=2;
    vector<vector<ll>> dp(n, vector<ll>(tot_sum+1,0));
    dp[0][0]=1;
    for(ll i=1;i<n;i++){
        for(ll j=0;j<=tot_sum;j++){
            dp[i][j]+=dp[i-1][j];
            if(j>=i) dp[i][j]+=(dp[i-1][j-i]%modn);
            dp[i][j]=dp[i][j]%modn;
        }
    }
    cout<<dp[n-1][tot_sum];
}