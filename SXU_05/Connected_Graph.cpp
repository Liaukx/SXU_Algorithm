#include <iostream>
using namespace std;
bool G[1000][1000];
// int dir[] = {1,0,-1,0,1};
void dfs(bool g[][1000],int row,int col,int len){
    if(!g[row][col]) return;
    g[row][col] = 0;
    for(int j = 0; j < len; ++ j){
        if(g[col][j]) {
            dfs(g,col,j,len);    
        };
        if(g[j][col]){
            dfs(g,j,col,len);    
        }
    }
}
int solve(bool g[][1000],int len){
    int ans=0;
    for(int i =0; i < len; ++ i){
        for(int j =i;j < len; ++j){
            if(!g[i][j]) continue;
            ans+=1;
            dfs(g,i,j,len);
        }
    }
    // cout << ans << endl;
    return ans;
} 
int main(){
    int n;
    cin >> n;
    // cout << n;
    int cur = 0;
    for (int i =0;i < n;++i){
        int tmp = 0;
        for(int j=0;j < n; ++j){
            cin>>G[i][j];
            tmp += G[i][j];
        }
        if (!tmp) cur += 1;
    }
    cout << solve(G,n) + cur << endl;
}