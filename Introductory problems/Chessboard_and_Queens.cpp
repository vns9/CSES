#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long ll;

ll ans=0;
vector<bool> cols(8,false);
vector<bool> ld(16,false);
vector<bool> rd(16,false);

void nqueens(ll row, vector<string>& board){
    if(row==8) ans++;
    else{
        for(ll c=0;c<8;c++){
            if(!cols[c]&&!ld[row+c]&&!rd[row-c+7]&&board[row][c]=='.'){
                cols[c]=ld[row+c]=rd[row-c+7]=true;
                nqueens(row+1, board);
                cols[c]=ld[row+c]=rd[row-c+7]=false;
            }
        }
    }
}

int main(){
    fio;
    vector<string> board(8);
    for(ll i=0;i<8;i++) cin>>board[i];
    nqueens(0,board);
    cout<<ans;
}