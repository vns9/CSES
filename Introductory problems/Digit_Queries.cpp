#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long ll;
//typedef long long ull;

int main(){
    fio;
    ll n; cin>>n;
    vector<ll>p(19);
    p[0]=1;
    for(ll i=1;i<=18;i++) p[i]=(p[i-1]*10);
    while(n!=0){
        ll d; cin>>d;
        ll currs=0;
        ll i=0;
        while(1){   
            if(d<(currs+(9*(i+1)*p[i]))) break;
            i++;
            currs+=(9*i*p[i-1]);
        }
        ll digits = i+1;
        // cout<<"digits "<<digits<<endl;
        // cout<<"currs "<<currs<<endl;
        ll numindex = (d-currs-1)/digits;
        // cout<<"numindex "<<numindex<<endl;
        if(d==currs){
            cout<<"9\n";
            n--;
            continue;
        }
        ll startno = p[digits-1];
        // cout<<"start no "<<startno<<endl;
        ll currnum = startno+numindex;
        // cout<<"currnum"<<currnum<<endl;
        ll pos = (d-currs-1)%(digits);
        // cout<<"pos "<<pos<<endl;
        cout<<to_string(currnum)[pos]<<"\n";
        n-=1;
    }
}