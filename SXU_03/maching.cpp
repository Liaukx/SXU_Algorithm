#include<iostream>
#include<stack>
using namespace std;
bool maching(string& s){
    stack<char> stk;
    for(int iter = 0; iter < s.length(); ++ iter){
        char cur = s[iter];
        if(cur == '(' || cur == '{' || cur == '['){
            stk.push(s[iter]);
            continue;
        }
        if(cur == ')' && stk.top() == '(' || cur == ']' && stk.top() == '[' || cur == '}' && stk.top() == '{') {
            stk.pop();
            continue;
        }
        if(cur == ')' || cur == ']' || cur == '}') return false;
    } 
    return stk.empty();
}
int main(){
    string s;
    cin >> s;
    cout << (maching(s) ? 1 : 0);
    return 0;
}