#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

int main(){
    ll h,w; cin>>h; cin>>w; 
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<ll>> visited(h, vector<ll>(w,0));
    map<pair<ll,ll>,char> frm;
    char tmp; ll p1,p2,t1,t2;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>tmp; grid[i][j]=tmp;
            if(grid[i][j]=='A'){
                p1=i;p2=j;
            }
            if(grid[i][j]=='B'){
                t1=i;t2=j;
            }
        }
    }
    queue<pair<ll,ll>> bfsq;
    bool found=false;
    bfsq.push(make_pair(p1,p2)); visited[p1][p2]=1;
    while(!bfsq.empty()){
        auto vertex=bfsq.front();
        ll i=vertex.first;
        ll j=vertex.second;
        bfsq.pop();
        if(i>=1){
            if(visited[i-1][j]==0&&grid[i-1][j]!='#'){
                visited[i-1][j]=1;
                bfsq.push(make_pair(i-1,j));
                frm[make_pair(i-1,j)]='U';
            }
        }
        if(i+1<h){
            if(visited[i+1][j]==0&&grid[i+1][j]!='#'){
                visited[i+1][j]=1;
                bfsq.push(make_pair(i+1,j));
                frm[make_pair(i+1,j)]='D';
            }
        }
        if(j>=1){
            if(visited[i][j-1]==0&&grid[i][j-1]!='#'){
                visited[i][j-1]=1;
                bfsq.push(make_pair(i,j-1));
                frm[make_pair(i,j-1)]='L';
            }
        }
        if(j+1<w){
            if(visited[i][j+1]==0&&grid[i][j+1]!='#'){
                visited[i][j+1]=1;
                bfsq.push(make_pair(i,j+1));
                frm[make_pair(i,j+1)]='R';
            }
        }
        
    }
    if(frm.find(make_pair(t1,t2))==frm.end()){
        cout<<"NO"; return 0;
    }
    vector<char> path; pair<ll,ll> curr=make_pair(t1,t2);
    while(curr.first!=p1||curr.second!=p2){
        path.push_back(frm[curr]);
        if(frm[curr]=='R'){
            curr.second-=1;
        }
        else if(frm[curr]=='L'){
            curr.second+=1;
        }
        else if(frm[curr]=='D'){
            curr.first-=1;
        }
        else if(frm[curr]='U'){
            curr.first+=1;
        }
    }
    cout<<"YES\n"<<path.size()<<"\n";
    reverse(path.begin(),path.end());
    for(auto step: path){
        cout<<step;
    }
}