#include<iostream>
using namespace std;
struct Node{
    int val = 0;
    Node * pre = NULL;
    Node * next = NULL;
    Node(){}
    Node(int val):val(val){}
};
class CycleLink{
public:
    Node * head;
    Node * Tail;
    int MaxLen;
    CycleLink(){
        head = NULL;
        Tail = NULL;
        MaxLen = 0;
    }
    void InsertAtHead(int val){
        if(head == NULL){
            head = new Node(val);
            head -> next = new Node();
            Tail = head -> next;
            Tail -> next = head;
            Tail -> pre = head;
            head -> pre = Tail;
            MaxLen += 1;
            return;
        }
        Node * cur = new Node(val);
        cur -> next = head;
        cur -> pre = Tail;
        head = cur;
        Tail -> next = head;
        head -> pre = Tail;
        // cout << (Tail -> next == head);
        MaxLen += 1;
    }
    void InsertAtTail(int val){
        if(head == NULL){
            return InsertAtHead(val);
        }
        Node * cur = new Node(val);
        cur -> next = Tail;
        cur -> pre = Tail -> pre;
        cur -> pre -> next = cur;
        Tail -> pre = cur;
        MaxLen += 1;
    }
    void show(){
        Node * cur = head;
        while(cur -> next != head){
            cout << cur->val << " ";
            cur = cur -> next;
        }
    }
    void show(Node * cur){
        Node * iter = cur;
        while(iter -> next != cur){
            if (iter == Tail) continue;
            cout << iter -> val << " ";
            iter  = iter -> next;
        }
        cout << cur -> val;
    }
    void deleteAtIdx(Node * cur){
        if (cur == head){
            // cout << head -> pre -> next -> val;
            head = cur -> next;
            head -> pre = cur -> pre;
            // cout << cur -> val;
            cur -> pre -> next = head;
            delete cur;
            return;
        }
        
        cur -> next -> pre = cur -> pre;
        cur ->pre -> next = cur -> next;
        delete cur;
    }

    void solve(){
        if(this->head  -> val > this->Tail->pre -> val){
            int tmp = this -> head -> val;
            this -> deleteAtIdx(this -> head);
            this -> InsertAtTail(tmp);
        }
        if(this -> head -> val < this -> head -> next -> val){
            return;
        }
        int tmp = this -> head -> val;
        this -> deleteAtIdx(this -> head);
        Node * cur =this -> head ;
        while(cur -> val < tmp){
            cur = cur -> next;
        }
        Node * Tmp = new Node(tmp);
        Tmp -> next = cur;
        Tmp->pre = cur -> pre;
        cur -> pre = Tmp;
        Tmp -> pre -> next = Tmp;
        // this -> show();
    }

};

int main(){
    int n ;
    cin >> n;
    CycleLink L = CycleLink();
    
    for(int i = 0; i < n; ++ i){
        int tmp;
        cin >> tmp;
        if (i == 0){
            L.InsertAtHead(tmp);
            continue;
        }
        L.InsertAtTail(tmp);
    }
    L.solve();
    L.show();
    return 0;
}