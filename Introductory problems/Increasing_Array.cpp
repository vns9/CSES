#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll cnt=0;
    vector<ll> v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n-1;i++){
        if(v[i+1]<v[i]){
            cnt+=(v[i]-v[i+1]);
            v[i+1]=v[i];
        }
    }
    cout<<cnt;
}