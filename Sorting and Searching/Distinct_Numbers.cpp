#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,temp; cin>>n;
    set<ll> s;
    for(ll i=0;i<n;i++){
        cin>>temp;
        s.insert(temp);
    }
    cout<<s.size();
}