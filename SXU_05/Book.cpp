#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    string id;
    string name;
    float price;
    Node(string id,string name,float price):id(id),name(name),price(price){}
};
void show(Node* cur){
    cout << cur -> id << " " << cur -> name << " ";
    cout.precision(4);
    cout.setf(ios::showpoint);
    cout <<  cur-> price << endl;
}
vector<Node*> Book;
bool cmp(Node*a,Node*b){
    return a->price > b -> price;
}
int main(){
    int n;
    cin >> n;
    string id,name;
    float price;
    for (int i  = 0; i < n; ++ i){
        cin >> id >> name >> price ;
        Book.push_back(new Node(id,name,price));
    }
    sort(Book.begin(),Book.end(),cmp);
    // cout << Book[0]->price << endl;
    // show(Book[0]);
    vector<Node * > ans;
    for (int i = 0; i < Book.size();++i){
        if(Book[i]->price < Book[0]->price) break;
        ans.push_back(Book[i]);
    }
    cout << ans.size() << endl;
    for (int i  = 0; i < ans.size(); ++ i){
        show(ans[i]);
    }
}