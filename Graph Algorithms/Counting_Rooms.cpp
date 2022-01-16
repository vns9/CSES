#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

void dfs(ll i, ll j, vector<vector<ll>>& visited, vector<vector<char>>& grid){
    if(i>=0 && i<visited.size() && j>=0 && j<grid[0].size()){
        if(grid[i][j]=='.' && visited[i][j]==0){
            visited[i][j]=1;
            dfs(i-1,j,visited,grid);
            dfs(i+1,j,visited,grid);
            dfs(i,j+1,visited,grid);
            dfs(i,j-1,visited,grid);
            visited[i][j]=2;
        }   
    }
}

int main(){
    ll n,m; cin>>n; cin>>m; char tmp; ll cnt=0;
    vector<vector<char>> grid(n, vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>tmp; grid[i][j]=tmp;
        }
    }
    vector<vector<ll>> visited(n, vector<ll>(m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(visited[i][j]==0 && grid[i][j]=='.'){
                cnt++;
                dfs(i,j,visited,grid);
            }
        }
    }
    cout<<cnt;
}