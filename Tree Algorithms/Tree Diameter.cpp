#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

ll diam = LONG_MIN;

ll helper(ll i, ll par, vector<vector<ll>>& child){
    ll dep1=0,dep2=0;
    for(auto node: child[i]){
        if(node==par) continue;
        ll currdepth = 1+helper(node,i,child);
        if(currdepth>dep1){
            dep2=dep1; dep1=currdepth;
        }
        else if(currdepth<=dep1&&currdepth>dep2){
            dep2=currdepth;
        }
    }
    //cout<<i<<" "<<dep1<<" "<<dep2<<endl;
    diam=max(diam,dep1+dep2);
    return dep1;
}

int main(){
    ll n; cin>>n;
    if(n==1){
        cout<<0; return 0;
    }
    vector<vector<ll>> child(n+1);
    for(ll i=1;i<=n-1;i++){
        ll a,b; cin>>a; cin>>b;
        child[a].pb(b);
        child[b].pb(a);
    }
    helper(1,-1,child);
    cout<<diam;
}