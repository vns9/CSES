#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n,temp; cin>>n;
    vector<ll>v(n);
    ll avg,cost=0;
    for(ll i=0;i<n;i++){
        cin>>temp; v[i]=temp;
    }
    sort(v.begin(),v.end());
    avg=v[n/2];
    for(ll i=0;i<n;i++){
        cost+=abs(avg-v[i]);
    }
    cout<<cost;
}