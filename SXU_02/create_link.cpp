#include <iostream>
#include<string>
using namespace std;
struct Node{
    string num;
    int score;
    Node * next;
    Node():next(nullptr),num(""),score(0){}
    Node(string num,int score):next(nullptr),num(num),score(score){}
    Node(string num,int score,Node * next):next(next),num(num),score(score){}
};
//有头节点
class ListNode{
private:
    Node * head;
public:
    ListNode(){
        this -> head = new Node();
    }
    void InsertAtHead(string num,int score){
        Node * tmp = head -> next;
        if (tmp != nullptr){
            head -> next = new Node(num,score,tmp);
        }else{
            InsertAtTail(num,score);
        }
    }
    void InsertAtTail(string num,int score){
        Node * cur = head;
        while(cur -> next){
            cur = cur -> next;
        }
        cur -> next = new Node(num,score);
    }
    void show(){
        Node * cur = head -> next;
        while(cur){
            cout << "[num=" <<cur -> num << ",score=" << cur -> score << "]" << endl;
            cur = cur -> next;
        }
    }
};
string PreProcess(string& num,int & score){
    int i ;
    string ans;
    for(i = 0; i < num.length(); ++ i){
        if (num[i] == ',') break;
        ans += num[i];
    }
    string tmp;
    for(++i ; i < num.length() ;++i){
        tmp += num[i];
    }
    score = stoi(tmp);
    return ans;
}
int main(){

   
    ListNode list = ListNode();
    string pre,num;
    for(int i = 0; i < 3; ++ i){
        int score = 0;
        cin >> pre;
        num = PreProcess(pre,score);
        list.InsertAtTail(num,score);
    }

    list.show();
    return 0;
}