#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        if(i==1) cout<<0<<"\n";
        else cout<<(i*i*(i*i-1)/2)-4*(i-1)*(i-2)<<"\n";
    }
}