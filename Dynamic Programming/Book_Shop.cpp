#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll modn = 1e9+7;

int main(){
    ll n,x,temp; cin>>n; cin>>x;
    vector<pair<ll,ll>> pp(n, make_pair(0, 0));
    for(ll i=0;i<n;i++){
        cin>>temp;
        pp[i].first=temp;
    }
    for(ll i=0;i<n;i++){
        cin>>temp;
        pp[i].second=temp;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(x+1,0));
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            ll left=j-(pp[i-1].first);
            if(left>=0) dp[i][j]=max(dp[i][j], dp[i-1][left]+pp[i-1].second);
        }
    }
    cout<<dp[n][x];
}