#include<iostream>
#define N 1000
using namespace std;
struct Node{
    int id;
    int cost;
    Node * next = nullptr;
    Node(int id,int cost):id(id),cost(cost){}
};
Node* G[N] = {nullptr};
void Insert(Node**g,int idx,int pot,int cost){
    if(g[idx] == nullptr) g[idx] = new Node(pot,cost);
    else{
        Node * cur = g[idx];
        while(cur != nullptr){
            cur = cur -> next;
        }
        cur = new Node(pot,cost);
    }
}
int _solve(Node **g,int size,int beg,int end){
    int ans;
    Node * beg = g[0];
    while(beg){
        
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for  (int i = 0 ; i < m ; ++ i){
        int a ,b , c;
        cin >> a >> b >> c;
        int t = a > b ? a:b;
        if(t != a){
            b = a;
            a = t;
        }
        Insert(G,a,b,c);
    }
    solve(G,n);
}