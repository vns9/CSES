#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n,x; cin>>n;
    vector <ll> dp;
    for(ll i=0;i<n;i++){
        cin>>x;
        auto iter=lower_bound(dp.begin(),dp.end(),x);
        if(iter==dp.end()) dp.push_back(x);
        else *iter=x;
    }
    cout<<dp.size();
}