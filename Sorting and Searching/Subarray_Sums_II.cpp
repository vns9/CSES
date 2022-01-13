#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    // ll n,temp,s; cin>>n; cin>>s;
    // multimap <ll, ll> imap;
    // imap.insert({0,-1});
    // ll curr=0,ans=0;
    // for(ll i=0;i<n;i++){
    //     cin>>temp;
    //     curr+=temp;
    //     imap.insert({curr,i});
    // }
    // for(auto kv: imap){
    //     auto itr1 = imap.lower_bound(kv.first+s);
    //     auto itr2 = imap.upper_bound(kv.first+s);
    //     while(itr1!=itr2){
    //         if((itr1->second)>kv.second && (itr1->first==kv.first+s)) ans++;
    //         itr1++;
    //     }
    // }
   
    // cout<<ans;
    ll n,temp,s; cin>>n; cin>>s;
    map <ll, ll> imap;
    ll curr=0,ans=0;
    imap[0]=1;
    for(ll i=0;i<n;i++){
        cin>>temp; curr+=temp;
        ans+=(imap[curr-s]);
        imap[curr]++;
    }
    cout<<ans;
}