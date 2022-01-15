#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll a,b; cin>>a; cin>>b;
    vector<vector<ll>>dp(a+1, vector<ll>(b+1,0));
    for(ll i=1;i<=a;i++) dp[i][1]=i-1;
    for(ll i=1;i<=b;i++) dp[1][i]=i-1;
    for(ll i=2;i<=a;i++){
        for(ll j=2;j<=b;j++){
            if(i!=j){
                ll ans=LONG_MAX;
                for(ll k=1;k<i;k++){
                    ans=min(ans, dp[k][j]+dp[i-k][j]+1);
                }
                for(ll k=1;k<j;k++){
                    ans=min(ans, dp[i][k]+dp[i][j-k]+1);
                }
                dp[i][j]=ans;
            }
            else dp[i][j]=0;
        }
    }
    cout<<dp[a][b];
}