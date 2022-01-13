#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x; cin>>n; cin>>x;
    vector<ll> v(n);
    map <ll,vector<ll>> cnt;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(cnt.find(v[i])==cnt.end()){
            vector<ll> temp; temp.push_back(i+1);
            cnt[v[i]]=temp;
        }
        else cnt[v[i]].push_back(i+1);
    }
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            ll rem=x-v[i]-v[j];
            if(cnt.find(rem)!=cnt.end()){
                for(ll k=0;k<cnt[rem].size();k++){
                    if(cnt[rem][k]!=(i+1)&&cnt[rem][k]!=(j+1)){
                        cout<<i+1<<" "<<j+1<<" "<<cnt[rem][k];
                        return 0;
                    }
                }
            }   
        }
    }
    cout<<"IMPOSSIBLE";
}