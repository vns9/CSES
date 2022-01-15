#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n,m,temp; 
    ll fans=1; 
    cin>>n; cin>>m;
    vector<ll> v(n,0); 
    vector<vector<ll>> dp(n+1, vector<ll>(m,0));
    for(ll i=0;i<n;i++){
        cin>>temp; v[i]=temp;
        if(i>0){
            if(v[i]!=0&&v[i-1]!=0){
                if(abs(v[i]-v[i-1])>1){
                    cout<<0; return 0;
                }
            }
        }
        if(v[i]>m){
            cout<<0; return 0;
        }
        if(v[i]!=0) dp[i+1][v[i]-1]=1;
    }
    if(n==1){
        if(v[0]==0){
            cout<<m; return 0;
        }
        else{
            cout<<1; return 0;
        }
    }
    if(v[0]==0){
        for(ll i=0;i<m;i++) dp[1][i]=1;
    }
    for(ll i=2;i<=n;i++){
        if(v[i-1]==0){
            for(ll j=0;j<m;j++){
                dp[i][j]+=(dp[i-1][j]%modn);
                dp[i][j]=dp[i][j]%modn;
                if(j+1<m) dp[i][j]+=(dp[i-1][j+1]%modn);
                dp[i][j]=dp[i][j]%modn;
                if(j>=1) dp[i][j]+=(dp[i-1][j-1]%modn);
                dp[i][j]=dp[i][j]%modn;
            }
            if(i==n){
                ll ans = 0;
                for(ll t=0;t<dp[i].size();t++){
                    ans+=dp[i][t]; ans=ans%modn;
                }
                fans*=(ans%modn);
                fans=fans%modn;
            }
            if(i<n){
                if(v[i]!=0){
                    ll ans=0;
                    for(ll k=0;k<m;k++){
                        if(abs(v[i]-(k+1))<=1) ans+=dp[i][k];
                    }
                    fans*=(ans%modn);
                    fans=fans%modn;
                }                
            }
        }     
    }
    cout<<fans;
}