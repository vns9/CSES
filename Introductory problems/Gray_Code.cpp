#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void gray(ll n, ll k){
    bitset<32> y(n ^ (n >> 1));
    cout<<y.to_string().substr(32-k)<<"\n";
}

int main(){
    ll n; cin>>n;
    for(ll i=0; i<pow(2,n); i++){
        gray(i, n);
    }
}