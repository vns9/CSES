#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, s, temp; cin>>n; cin>>s;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++){
        cin>>temp; v.push_back(make_pair(temp, i+1)); 
    }
    sort(v.begin(),v.end());
    ll start=0, end=n-1;
    ll a1=-1,a2=-1;
    while(start<end){
        if((v[start].first+v[end].first)==s){
            a1=v[start].second; a2=v[end].second;
            break;
        }
        if((v[start].first+v[end].first)<s){
            start++;
            continue;
        }
        if((v[start].first+v[end].first)>s){
            end--;
            continue;
        }
    }
    if(a1==-1&&a2==-1) cout<<"IMPOSSIBLE";
    else cout<<a1<<" "<<a2;
}