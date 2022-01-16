#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n,m,q; cin>>n; cin>>m; cin>>q;
    vector<vector<ll>> fw(n+1, vector<ll>(n+1,LONG_MAX/1000));
    for(ll i=1;i<=n;i++) fw[i][i]=0;
    for(ll i=0;i<m;i++){
        ll a,b,c; cin>>a; cin>>b; cin>>c;
        fw[a][b]=min(fw[a][b],c);
        fw[b][a]=min(fw[b][a],c);
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                fw[i][j]=min(fw[i][j], fw[i][k]+fw[k][j]);
            }
        }
    }
    for(ll i=0;i<q;i++){
        ll a,b; cin>>a; cin>>b;
        if(fw[a][b]>5e11) cout<<"-1"<<"\n";
        else cout<<fw[a][b]<<"\n";
    }
}