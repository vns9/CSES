#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n; cin>>n;
    multiset<ll> tow;
    ll temp;
    for(ll i=1;i<=n;i++){
        cin>>temp;
        auto it = tow.upper_bound(temp);
        if(it==tow.end()) tow.insert(temp);
        else{
            tow.erase(it);
            tow.insert(temp);
        }
    }
    cout<<tow.size();
}