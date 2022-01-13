#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,temp; cin>>n;
    map <ll, ll> imap;
    ll curr=0,ans=0;
    imap[0]=1;
    ll index;
    for(ll i=0;i<n;i++){
        cin>>temp; curr+=temp;
        if((curr%n)>=0) index = curr%n;
        else index = (curr%n)+n;
        ans+=(imap[index]);
        imap[index]++;
    }
    cout<<ans;
}