#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<n;
        return 0;
    }
    if(n==3||n==2) cout<<"NO SOLUTION";
    else{
        vector<ll> eve;
        vector<ll> odd;
        bool check=true;
        for(ll i=n;i>=1;i--){
            if(check){
                eve.push_back(i);
                check=false;
            }
            else{
                odd.push_back(i);
                check=true;
            }
        }
        for(auto element: odd) cout<<element<<" ";
        for(auto element: eve) cout<<element<<" ";
    }
}