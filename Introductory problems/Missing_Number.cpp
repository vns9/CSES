#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,sum=0;
    cin>>a;
    for(int i=0;i<a-1;i++){
        ll temp;
        cin>>temp;
        sum+=temp;
    }
    cout<<(a*(a+1)/2)-sum;
}