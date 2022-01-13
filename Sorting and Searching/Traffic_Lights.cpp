#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll x,temp,n; cin>>x; cin>>n;
    set<ll> traf;
    multiset <ll> diff;
    traf.insert(0); traf.insert(x);
    diff.insert(x);
    for(ll i=0;i<n;i++){
        cin>>temp;
        auto it = traf.upper_bound(temp);
        auto before = it; --before;
        diff.insert(*it-temp);
        diff.insert(temp-*before);
        diff.erase(diff.find(*it-*before));
        traf.insert(temp);
        cout<<*diff.rbegin()<<" ";
    }
}