#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fact(ll a){
    ll ans=1;
    for(ll i=1;i<=a;i++) ans*=i;
    return ans;
}
int main(){
    string s; cin>>s;
    sort(s.begin(), s.end());
    ll tot_perm=fact(s.length());
    vector<ll> ccnt;
    char curr=s[0];
    ll currcnt=1;
    for(ll i=1;i<s.length();i++){
        if(s[i]==curr){
            currcnt+=1;
            if(i==s.length()-1) ccnt.push_back(currcnt);
        } 
        else{
            ccnt.push_back(currcnt);
            currcnt=1;
            curr=s[i];
        }
    }
    for(auto element: ccnt) tot_perm/=fact(element);
    cout<<tot_perm<<"\n";
    cout<<s<<"\n";
    while(next_permutation(s.begin(),s.end())){
        cout<<s<<"\n";
    }
}