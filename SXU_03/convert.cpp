#include<iostream>
#include<stack>
#include<vector>
int base = 8;
using namespace std;
void convert(int n){
    stack<int> ans;
    while(n){
        ans.push(n%base);
        n = n/base;
    }
    vector<int> res;
    while(!ans.empty()){
        res.push_back (ans.top());
        ans.pop();
    }
    for(int i = 0; i < res.size(); ++ i){
        cout << res[i];
    }
}
int main(){
    int n;
    cin >> n;
    if(n <= 0){
        cout << 0 << endl;
        return 0;
    }
    convert(n);
    return 0;
}