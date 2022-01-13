#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll ans=1;
    ll m = 1000000007;
    if(n%2==0){
        for(ll i=0;i<n/2;i++){
            ans=(ans*4)%m;
        }
    }
    if(n%2==1){
        for(ll i=0;i<n/2;i++){
            ans=(ans*4)%m;
        }
        ans=(ans*2)%m;
    }
    cout<<ans;
}