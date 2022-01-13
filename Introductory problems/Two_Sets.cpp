#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    vector<ll> v1;
    vector<ll> v2;
    if(n%4==1||n%4==2){
        cout<<"NO";
        return 0;
    } 
    else{
        cout<<"YES\n";
        if(n%4==0){
            for(ll i=1;i<=n;i++){
                if(i%4==0||i%4==1) v1.push_back(i);
                else v2.push_back(i);
            }
        }
        if(n%4==3){
            v1.push_back(3);
            v2.push_back(1);
            v2.push_back(2);
            for(ll i=4;i<=n;i++){
                if(i%4==0||i%4==3) v1.push_back(i);
                else v2.push_back(i);
            }
        }
    }
    cout<<v1.size()<<"\n";
    for(auto element: v1) cout<<element<<" ";
    cout<<"\n";
    cout<<v2.size()<<"\n";
    for(auto element: v2) cout<<element<<" ";
    
}