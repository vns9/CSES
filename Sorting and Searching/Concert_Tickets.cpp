#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m; cin>>n; cin>>m;
    multiset <ll> con;
    ll temp;
    for(ll i=0;i<n;i++){
        cin>>temp; con.insert(temp);
    }
    for(ll i=0;i<m;i++){
        cin>>temp;
        auto ptr = con.upper_bound(temp);
        if(ptr==con.begin()){
            cout<<"-1\n"; continue;
        }
        --ptr;
        cout<<*(ptr)<<"\n";
        con.erase(ptr);
        continue;   
    }   
}