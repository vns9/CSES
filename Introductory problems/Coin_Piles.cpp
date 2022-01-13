#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b; cin>>n;
    while(n!=0){
        cin>>a>>b;
        if(a%3==0&&b%3==0&&a<=2*b&&b<=2*a) cout<<"YES\n";  
        else if(a%3==2&&b%3==1&&a<=2*b&&b<=2*a) cout<<"YES\n";  
        else if(a%3==1&&b%3==2&&b<=2*a&&a<=2*b) cout<<"YES\n";  
        else cout<<"NO\n"; 
        n-=1;
    }
}