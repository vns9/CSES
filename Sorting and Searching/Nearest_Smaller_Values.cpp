#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,temp; cin>>n;
    stack <pair<ll,ll>> smal;
    for(ll i=1;i<=n;i++){
        cin>>temp;
        while(!smal.empty()){
            if(smal.top().first>=temp) smal.pop();
            else break;
        }
        if(!smal.empty()) cout<<smal.top().second<<" ";
        else cout<<0<<" ";
        smal.push(make_pair(temp,i));
    }
}