#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void toh(ll n, ll from, ll use, ll to){
    if(n>0){
        toh(n-1, from, to, use);
        cout<<from<<" "<<to<<"\n";
        toh(n-1, use, from, to);
    }
}

int main(){
    ll n; cin>>n;
    cout<<pow(2,n)-1<<'\n';
    toh(n,1,2,3);
}