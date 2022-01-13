#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,temp,s; cin>>n; cin>>s;
    multiset<ll> sumtil;
    ll curr=0,ans=0;
    sumtil.insert(0);
    for(ll i=0;i<n;i++){
        cin>>temp;
        curr+=temp;
        sumtil.insert(curr);
    }
    for(auto it = sumtil.begin(); it!=sumtil.end(); it++){
        if(sumtil.find(s+(*it))!=sumtil.end()){
            ans++;
        }
    }
    cout<<ans;
}