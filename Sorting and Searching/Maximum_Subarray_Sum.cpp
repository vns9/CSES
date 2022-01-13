#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,temp; cin>>n;
    ll minv=LONG_MAX,maxv=LONG_MIN;
    ll cmax=LONG_MIN, curr=0;
    for(ll i=0;i<n;i++){
        cin>>temp;
        maxv=max(temp,maxv);
        minv=min(temp,minv);
        if(temp+curr>=0){
            curr+=temp;
            cmax=max(cmax,curr);
        }
        else curr=0;
    }
    if(maxv<0) cout<<maxv;
    else cout<<cmax;
}