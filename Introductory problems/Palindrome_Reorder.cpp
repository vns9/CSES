#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin>>s;
    deque<char> ans;
    vector<ll> v(26,0);
    ll oddc=0;
    for(ll i=0;i<s.length();i++){
        v[s[i]-'A']++;
    }
    for(ll i=0;i<26;i++){
        if(v[i]%2==1) oddc+=1;
    }
    if(oddc>1){
        cout<<"NO SOLUTION";
    }else{
        ll oddi=-1;
        for(ll i=0;i<v.size();i++){
            if(v[i]%2==1){
                oddi=i;
                break;
            }
        }
        if(oddi!=-1){
            char c='A'+oddi;
            for(ll j=0;j<v[oddi];j++) ans.push_back(c);
        }
        for(ll i=0;i<v.size();i++){
            if(v[i]%2==0){
                ll temp=v[i]/2;
                char c='A'+i;
                for(ll j=0;j<temp;j++){
                    ans.push_front(c);
                    ans.push_back(c);
                }
            }
        }
        for(auto el: ans) cout<<el;
    }
    return 0;
}