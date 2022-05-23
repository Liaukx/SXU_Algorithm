#include<iostream>
#include<stack>

using namespace std;
string s;
void solve(string& s){
    stack<int> stk;
    for(int i = 0; i < s.length(); ++ i){
        switch (s[i])
        {
        case 'x':
        {
            int tmp = stk.top();
            stk.pop();
            stk.push(tmp * (s[i+1] - '0'));
            i += 1;
            break;
        }
        case '/':
        {
            int tmp = stk.top();
            stk.pop();
            stk.push(tmp / (s[i+ 1] - '0'));
            i += 1;
            break;
        }        
        case '-':
        {
            stk.push( 0-(s[i+1]-'0'));
            i += 1;
            break;
        }
        case '+':
        {
            // i+= 1;
            break;
        }        
        default:
            stk.push(s[i] - '0');
            // cout << "*" << s[i] - '0';
            break;
        }
    }
    int tmp = stk.top();
    stk.pop();
    while (!stk.empty())
    {
        tmp += stk.top();
        stk.pop();
    }
    if(tmp == 24) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main(){
    int n ;
    cin >> n;
    for (int i = 0; i < n; ++ i){
        cin >> s;
        solve(s);
    }
}