#include <iostream>
#include<string>
#include<vector>

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
        if (tmp != nullptr){
            head -> next = new Node(val,tmp);
        }else{
            InsertAtTail(val);
        }
    }
    void InsertAtTail(int val){
        Node * cur = head;
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
void mergeList(ListNode& l1,ListNode &l2){
    Node* p1,*p2;
    p1 = l1.head->next;
    p2 = l2.head->next;
    ListNode ans = ListNode();
    // vector<int> ans;
    int Min = -1000000;
    while(p1 || p2){
        while(p1 && p2){
            while(p1&&p2 && p1 -> val <= p2 -> val){
               // ans.push_back(p1->val);
                if(p1->val > Min){
                    Min = p1->val;
                    ans.InsertAtTail(p1->val);
                }
                p1 = p1->next;
            }
            while(p2&&p1 && p1 -> val > p2->val ){
                
                // ans.push_back(p2->val);
                if(p2->val > Min){
                    Min = p2->val;
                    ans.InsertAtTail(p2->val);
                }
                p2 = p2->next;
            }
        }
        if(p1){
            
            // ans.push_back(p1->val);
            if(p1->val > Min){
                Min = p1->val;
                ans.InsertAtTail(p1->val);
            }
            p1 = p1->next;
        }
        if(p2){
            
            // ans.push_back(p2->val);
            if(p2->val > Min){
                Min = p2->val;
                ans.InsertAtTail(p2->val);
            }
            p2 = p2->next;
        }
    }
    
    ans.show();
}

int main(){
    ListNode L1 = ListNode();
    ListNode L2 = ListNode();

    int tmp;
    while(cin.peek() != '\n'){
        cin >> tmp;
        L1.InsertAtTail(tmp);
       
    }
    getchar();
    while(cin.peek() != EOF){
        cin >> tmp;
        L2.InsertAtTail(tmp);
       
    }

    mergeList(L1,L2);
    return 0;
}