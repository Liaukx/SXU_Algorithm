#include<iostream>
#define N 12000
using namespace std;
// 用带头结点的链表做
struct Node{
    int xb,xe,yb,ye,id;
    Node(int xb,int xe,int yb,int ye,int id):xb(xb),xe(xe),yb(yb),ye(ye),id(id){}
    Node():xb(0),xe(0),yb(0),ye(0),id(0){}
    Node* next = nullptr;
    Node* pre = nullptr;
};
bool inWind(Node* cur,int x,int y){
    if(cur -> xb <= x && cur -> yb >= x && cur -> xe <= y && cur -> ye >= y) return true;
    return false;
}
class List{
private:
    
    Node * Head;
public:
    
    List (int xb,int xe,int yb,int ye){
        Head = new Node();
        Head->next = new Node(xb,xe,yb,ye,1);
        Head -> next -> pre = Head;
    }
    List (Node** array,int len){
        Head = new Node();
        for (int i= 0; i < len; ++ i){
            // Node * cur = Head -> next;
            array[i] -> pre = Head;
            if(i > 0) Head -> next -> pre = array[i];
            array[i] -> next = Head -> next;
            Head -> next = array[i];
        }
    }
    void show(){
        if (Head -> next == nullptr) return;
        Node * cur = Head-> next;
        while(cur != nullptr){
            cout <<cur -> id << " " <<cur -> xb << " " << cur -> xe << " " << cur -> yb << " "<< cur -> ye << endl;
            cur = cur -> next;
        }
    }
    void operation(int x,int y){
        Node * cur = Head -> next;
        // int cnt = 1;
        while(cur != nullptr){
            if(inWind(cur,x,y)){
                
                // show();
                cout << cur -> id << endl;
                if(cur == Head -> next) return;
                cur -> pre -> next = cur -> next;
                if(cur -> next)cur -> next -> pre = cur ->pre;
                cur -> pre = Head;
                cur -> next = Head -> next;
                Head -> next = cur;

                // show();
                return;
            }
            // cnt += 1;
            cur = cur -> next;
        }
        cout << "IGNORED" << endl;
    }
};
int main(){
    int n,m;
    cin >> n >> m;
    Node* array[N] ;
    for (int i = 0; i < n; ++  i){
        int xb,xe,yb,ye;
        cin >> xb >> xe >> yb >> ye;
        array[i] = new Node(xb,xe,yb,ye,i+1);
    }
    List l(array,n);
    // l.show();
    for(int i = 0; i < m; ++ i){
        int x,y;
        cin >> x >> y;
        l.operation(x,y);
    }
}