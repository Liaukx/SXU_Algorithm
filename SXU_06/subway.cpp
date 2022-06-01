#include <iostream>
#define N 1005
using namespace std;
struct  Node
{
    int idx = 0;
    int weight;
    Node * next;
    Node(int idx,int weight):idx(idx),weight(weight),next(nullptr){}
    Node():weight(0),next(nullptr){}
};
// 用邻接表存储
Node * G[N] = {nullptr};

// bool visit[N] = {false};
void Insert(Node** G,int beg,int end,int val){

    if(G[beg] == nullptr){
        G[beg] = new Node();
    } 
    Node * cur = G[beg];
    while(cur->next != nullptr){
        cur = cur -> next;
    }
    cur->next = new Node(end,val);
}

void show(Node**G,int n){
    for (int i = 0; i <= n; ++ i){
        if(G[i] != nullptr){
            Node * cur = G[i]-> next;
            cout << i << "* ";
            while(cur != nullptr){
                cout << cur -> idx << "-" <<cur -> weight << " ";
                cur = cur -> next;
            }
            cout << "\n";
        }
    }
}
bool vis[N][N] = {0};

int max(int a,int b){
    return a>b ? a :b;
}
int min(int a,int b){
    return a<b ? a :b;
}

int dfs(int beg,int end,int curMax,int ans){
    // cout << beg << " ";
    if(beg == end){
        return curMax;
    }
    Node * cur = G[beg] -> next;
    // int ans =N;
    while(cur != nullptr){
        curMax = cur -> weight;
        int pre = curMax;
        curMax = max(curMax,dfs(cur->idx,end,curMax,ans));
        ans = min(ans,curMax);
        // 回溯
        cur = cur -> next;
        curMax = pre;
    }
    
    return ans;
}
void solve(int size){
    int ans = N;
    Node * cur = G[1];
    ans = min(dfs(1,size,cur->weight,ans),ans);
    cout << ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; ++ i){
        G[i] = nullptr;
    }
    for(int i = 0; i < m; ++ i){
        int beg,end,val;
        cin >> beg >> end >> val;
        Insert(G,beg,end,val);
        // G[beg] = new Node(end,val);
    }
    // show(G,n);
    solve(n);
}