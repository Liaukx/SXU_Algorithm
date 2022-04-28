#include<iostream>
using namespace std;

struct Node{
    
    int val;
    Node * next;
    Node():next(nullptr),val(0){}
    Node(int val):next(nullptr),val(val){}
    Node(int val,Node * next):next(next),val(val){}
};
//有头节点
class ListNode{
public:
    Node * head;
    ListNode(){
        this -> head = new Node();
    }
    void InsertAtHead(string ,int val){
        Node * tmp = head -> next;
        // this->size += 1;
        if (tmp != nullptr){
            head -> next = new Node(val,tmp);
        }else{
            InsertAtTail(val);
        }
    }
    void InsertAtTail(int val){
        Node * cur = head;
        // this->size += 1;
        while(cur -> next){
            cur = cur -> next;
        }
        cur -> next = new Node(val);
    }
    void show(){
        Node * cur = head -> next;
        while(cur){
            cout << cur ->val << " ";
            cur = cur -> next;
        }
    }
    // pos 从0开始
    int getItem(int pos){
        Node * cur = head -> next;
        for(int i = 0 ; i < pos; ++ i){
            cur = cur -> next;
        }
        return cur->val;
    }
};
void LastK(ListNode& list,int k){
    
    Node * slow = list.head -> next;
    Node * fast = list.head -> next;
    int dif = 0;
    while(fast){
        if(dif < k  && fast){
            ++ dif;
            fast = fast -> next;
        }
        else{
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    if(dif < k && !fast) {
        cout << "Not Found" << endl;
        return;
    }
    cout << slow ->val << endl;
    return;
}
int main(){
    int tmp;
    ListNode list = ListNode();
    int k ;
    cin >> k;
    while(cin >> tmp){
        list.InsertAtTail(tmp);
    }
    LastK(list,k);
    return 0;
}