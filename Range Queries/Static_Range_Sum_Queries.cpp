#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n,q; cin>>n; cin>>q;
    vector<ll> prefix(n+1,0); 
    ll curr=0; ll tmp;
    for(ll i=1;i<=n;i++){
        cin>>tmp; curr+=tmp; prefix[i]=curr;
    }
    ll a,b;
    for(ll i=0;i<q;i++){
        cin>>a; cin>>b; cout<<prefix[b]-prefix[a-1]<<"\n";
    }
}