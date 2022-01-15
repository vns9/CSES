#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll maxsum=0;
    for(ll i=0;i<n;i++) maxsum+=v[i];
    vector<vector<bool>> dp(n+1, vector<bool>(maxsum+1,false));
    dp[0][0]=true;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=maxsum;j++){
            dp[i][j]=dp[i-1][j];
            ll left=j-v[i-1];
            if(left>=0&&dp[i-1][left]){
                dp[i][j]=true;
            }
        }
    }
    ll cnt=0;
    for(ll i=1;i<=maxsum;i++){
        if(dp[n][i]) cnt++;
    }
    cout<<cnt<<"\n";
    for(ll i=1;i<=maxsum;i++){
        if(dp[n][i]) cout<<i<<" ";
    }
}