#include <iostream>
using namespace std;
struct Node{
    Node * next;
    int val;
    Node(): next(nullptr),val(0){}
    Node(int val):val(val),next(nullptr){}
    Node(int val , Node * next): val(val),next(next){}
};
void solve(Node* tree){
    Node * cur  = tree;
    if (cur -> next == nullptr || cur -> next -> next == nullptr || cur -> next -> val < cur -> next -> next -> val) return;
    cur = tree -> next -> next;
    while(cur->next != nullptr && cur->next ->val < tree ->next -> val){
        cur = cur -> next;
    }
    if(cur-> next != nullptr){
        Node * head = tree -> next -> next;
        Node * tmp = cur -> next;
        cur -> next = tree -> next;
        tree -> next -> next = tmp;
        tree -> next = head;
    }
    else{
        Node * head = tree -> next;
        tree-> next = tree -> next -> next;

        cur->next  = head;

        head -> next = nullptr;
    }
}
int main(){
    int n ;
    cin >> n;
    Node * head = new Node();
    Node * cur = head;
    //有头节点
    for(int i = 0; i < n; ++ i){
        int tmp;
        cin >> tmp;
        cur -> next = new Node();
        cur = cur -> next;
        cur -> val = tmp;
    }
    solve(head);
    cur = head -> next;
    for(cur; cur -> next != nullptr; cur = cur->next){
        cout << cur -> val << " ";
    }
    cout << cur -> val;
}