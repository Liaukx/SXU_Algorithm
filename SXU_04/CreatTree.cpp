#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

//获取结点的值 多位整数的情形
int getNum(string & s,int beg){
    int ans = 0;
    stack<int> num;
    for(int i = beg; i< s.length(); ++ i){
        if('0'<=s[i] && '9' >= s[i]){
            num.push(s[i]-'0');  
        }else{
            break;
        }
    }
    int Len = num.size();
    for (int i = 0; i<Len; ++ i){
        ans += num.top() * pow(10,i);
        num.pop();
    }
    return ans;
}

class BinaryTree{
private:
    //结点
    struct TreeNode
    {
        int val;
        TreeNode* lchild = nullptr;
        TreeNode* rchild = nullptr;
        TreeNode(int val):val(val){}
    };
    //根结点
    TreeNode * root;
    //先序遍历
    void _show(TreeNode * root){
        if (root == nullptr) return;
        cout << root ->  val;
        _show(root -> lchild);
        _show(root -> rchild);
    }
    //按照层输出
    void _showLev(TreeNode* root){
        queue <vector<TreeNode*>> Que;
        stack <vector<TreeNode*>> stk;
        vector<TreeNode*> tmp;
        tmp.push_back(root);
        Que.push(tmp);
        while(!Que.empty()){
            //tmp 表示上一层的结点
            tmp = Que.front();
            Que.pop();
            //stk 是每一层的结点。因为从下往上输出，所以用栈
            stk.push(tmp);
            //cur 记录下一层的结点
            vector<TreeNode*> cur;
            for(int i = 0;i < tmp.size(); ++ i){
                if(tmp[i] -> lchild != nullptr){
                    cur.push_back(tmp[i]->lchild);
                }
                if(tmp[i] -> rchild != nullptr){
                    cur.push_back(tmp[i]->rchild);
                }
            }
            //如果下一层没有新结点
            if(cur.size() < 1) break;
            Que.push(cur);
        }
        //输出每一层的结果
        while(!stk.empty()){
            vector<TreeNode*> cur = stk.top();
            for(int i = 0; i< cur.size(); ++ i){
                cout << cur[i]->val << " ";
            }cout << endl;
            stk.pop();
        }
        return ;
    }
public:

    BinaryTree(string & s){
        if(s.length() == 0){
            root = nullptr;
            return;
        }
        stack<TreeNode*> stk;
        TreeNode* cur = new TreeNode(s[0]-'0');
        stk.push(cur);
        bool tag;
        //建树
        //如果是）出栈
        //如果是( 下一个数是栈顶的左孩子，然后进栈，需要一个标记
        //如果是，下一个次，先出栈，是新栈顶的右孩子，然后进栈
        for(int i = 1; i< s.length(); ++ i){
            switch (s[i]){
                case '(':
                    tag = 1;
                    break;
                case ')':
                    tag = 2;
                    stk.pop();
                    break;
                case ',':
                    tag = 0;
                    break;
                default:
                {
                    if (tag){
                        int c = getNum(s,i);
                        cur = new TreeNode(c);
                        i += int(log10(c));
                        TreeNode * tmp = stk.top();
                        tmp -> lchild = cur;
                        stk.push( cur );
                    }else{
                        int c = getNum(s,i);
                        cur = new TreeNode(c);
                        i += int(log10(c));
                        stk.pop();
                        TreeNode * tmp = stk.top();
                        tmp -> rchild = cur;
                        stk.push(cur);
                    }
                }
            }
        }
        root = stk.top();
        stk.pop();
    }
    void show(){
        return _show(this -> root);
    }

    void showLev(){
        _showLev(root);
    }

};

int main(){
    vector<int>(3);
    string s;
    cin >> s;
    BinaryTree tree = BinaryTree(s);
    tree.showLev();
}