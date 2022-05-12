#include <iostream>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;

//Haffman_Tree
struct TreeNode
{
    int val = 0;
    TreeNode* lchild = nullptr; 
    TreeNode* rchild = nullptr;
    // TreeNode* father = nullptr;
    TreeNode(int val ) :val(val){}
};

struct cmp{
    bool operator()(TreeNode* a,TreeNode* b){
       	return a->val>b->val;//最小堆
      	//return a.val<b.val;//最大堆
    }
};

class HaffmanTree{
public:
    TreeNode * root;
    HaffmanTree(int val){
        root = new TreeNode(val);
    }
    HaffmanTree(int * array,int len){
        //利用优先队列建树
        priority_queue <TreeNode*,vector<TreeNode*>,cmp> que;
        for(int i = 0; i<len; ++ i){
            que.push(new TreeNode(array[i]));
        }
        while(que.size() != 1){

            TreeNode* cur1 = que.top();
            que.pop();
            TreeNode* cur2 = que.top();
            que.pop();
            TreeNode *rootCur;
            rootCur = new TreeNode(cur1-> val + cur2-> val);
            rootCur -> rchild = cur1;
            rootCur -> lchild = cur2;
            que.push(rootCur);
        }
        root = que.top();
        que.pop();
    }
};
void show(TreeNode* root){
    if (root == NULL) return;
    cout << root -> val << " ";
    show(root -> lchild);
    show(root -> rchild);
    return;
}
//求wpl
int calWPL(TreeNode* root,int depth){
    if(root -> lchild == nullptr && root -> rchild == nullptr){
        return root -> val * depth;     
    }
    int wpl = 0;
    if(root -> lchild){
        wpl += calWPL(root -> lchild,depth + 1);
    }
    if(root -> rchild){
        wpl += calWPL(root -> rchild,depth + 1);
    }
    return wpl;
}

int main(){

    int* A = new int[10];
    int n;
    cin >> n;
    for (int  i = 0; i < n; ++ i){
        int tmp;
        cin >> tmp;
        A[i] = tmp;
    }
    HaffmanTree tree = HaffmanTree(A,n);
    cout <<calWPL(tree.root,0);
}