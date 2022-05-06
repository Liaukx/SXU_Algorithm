// https://zhuanlan.zhihu.com/p/135433833
#include<iostream>
#include<stack>
using namespace std;

void solve(string s){
    stack<char> stk;
    for(int iter = 0; iter < s.length() - 1; ++ iter){
        if ('A'<=s[iter] && 'Z' >= s[iter]) {
            cout << s[iter];
            // continue;
        }else if(s[iter] == '('){
            stk.push(s[iter]);
        }
        else if (s[iter] == ')'){
            while(stk.top() != '('){
                cout << stk.top();
                stk.pop();
            }
            stk.pop(); 
            // continue;
        }       
        else{
            if (stk.empty() || stk.top() == '('){
                stk.push(s[iter]);
            }else {
                while(!stk.empty() && stk.top() != '(' && (stk.top() == '*' || stk.top() == '/')){
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s[iter]);
            }
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
    return ;
}
int main(){
    string s;
    cin >> s;
    solve(s);
    return 0;
}

