// 回文字符串
#include<iostream>
using namespace std;
bool is_Palind(string & s){
    int l = 0 ,r = s.length() -1;
    while(l < r){
        if(s[l ++ ] != s[r --]) return false;
    }
    return true;
}
int main(){
    string s; 
    cin >> s;
    cout << (is_Palind(s) ?"yes":"no");
    return 0;
}