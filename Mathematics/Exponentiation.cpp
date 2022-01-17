#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll n; cin>>n; ll a,b;
    while(n--){
        cin>>a; cin>>b;
        ll curr=a; ll ans=1;
        string s = bitset<64>(b).to_string();
        reverse(s.begin(),s.end());
        for(ll i=0;i<s.length();i++){
            if(s[i]!='0') ans=(ans*curr)%modn;
            curr = ((curr%modn)*(curr%modn))%modn;
        }
        cout<<ans<<"\n";
    }
}