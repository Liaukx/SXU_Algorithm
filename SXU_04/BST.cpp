#include<iostream>
using namespace std;
class BST{
private:
    struct TreeNode
    {
        int val = 0;
        TreeNode * lchild = nullptr;
        TreeNode * rchild = nullptr; 
        TreeNode(int val):val(val){}
    };

    void _show(TreeNode* root){
        if (root == NULL) return;
        _show(root -> lchild);
        cout << root -> val << " ";
        _show(root -> rchild);
        return;
    }
    TreeNode * root;
public:
    BST(int* array,int Len){
        root = new TreeNode(array[0]);
        for(int i = 1;i < Len; ++ i){
            insert(root,array[i]);
        }
    }
    //相等的时候选择一支插入
    TreeNode* insert(TreeNode* root,int val){
        if(root == nullptr ) return root;
        
        if (val <= root -> val && root -> lchild == nullptr){
            root -> lchild = new TreeNode(val);
            return root;
        }
        else if(val > root -> val && root -> rchild == nullptr){
            root -> rchild = new TreeNode(val);
            return root;
        }
        else if(val <= root -> val){
            root ->lchild = insert(root -> lchild,val);
        }
        else{
            root ->rchild = insert(root -> rchild,val);
        }
        return root;
    }
    void show(){
        _show(root);
    }
};


int main(){
    int n;
    cin >> n;
    int* A = new int[100];
    for(int i = 0; i< n; ++ i){
        cin >> A[i];
    }
    BST bst = BST(A,n);
    bst.show();
}