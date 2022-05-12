#include<iostream>
#include<unordered_map>
using namespace std;
class Tree{
private:
    struct TreeNode{
        char val;
        TreeNode* lchild = nullptr;
        TreeNode* rchild = nullptr;
        TreeNode(char val):val(val){};
    };
    TreeNode * root;
    void _show(TreeNode* root){
        if(root == nullptr) return;
        cout << root -> val;
        _show(root -> lchild);
        _show(root -> rchild);
    }
public:
    unordered_map<char,int> Hash;
    TreeNode* _Tree(string& inord,string& postord,int start_i,int end_i,int start_p,int end_p){
        if(start_i > end_i || start_p > end_p) return nullptr;
        TreeNode * root = new TreeNode(postord[end_p]);
        int Lsize = Hash[postord[end_p]] - start_i;
        root -> lchild = _Tree(inord,postord,start_i,Hash[postord[end_p]] - 1,start_p,start_p + Lsize - 1);
        root -> rchild = _Tree(inord,postord,Hash[postord[end_p]] + 1,end_i,start_p + Lsize ,end_p-1);
        return root;
    }
    Tree(string& inord,string& postord){
        for (int i = 0; i < inord.length(); ++ i){
            Hash[inord[i]] = i;
        }
        root = _Tree(inord,postord,0,inord.length()-1,0,postord.length()-1);
    }
    void show(){
        return _show(root);
    }
};
int main(){
    string inord,postord;
    cin >> inord  >> postord;
    Tree tree = Tree(inord,postord);
    tree.show();
}