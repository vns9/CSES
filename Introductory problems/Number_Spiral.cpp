#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x,y;
    cin>>n;
    while(n--){
        cin>>y>>x;
        if(x>y){
            if(x%2==1){
                cout<<(x*x)-y+1<<"\n";
            }else{
                cout<<((x-1)*(x-1))+y<<"\n";
            }
        }
        if(y>x){
            if(y%2==0){
                cout<<(y*y)-x+1<<"\n";
            }else{
                cout<<x+((y-1)*(y-1))<<"\n";
            }
        }
        if(x==y){
            if(x%2==1){
                cout<<(x*x)-y+1<<"\n";
            }else{
                cout<<((x-1)*(x-1))+y<<"\n";
            }
        }
    }
}