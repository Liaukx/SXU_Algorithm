#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

int main(){
    int tmp,n = 0;
    unordered_map <int,int> map;
    while(cin >> tmp ){
        map[tmp] ++;
        ++ n;
    }
    int cnt = 0,ans;
    for (auto i : map){
        if(i.second > cnt){
            ans = i.first;
            cnt = i.second;
        }
    }
    if (cnt > n/2){
        cout << ans;
        return 0;
    }
    printf("-1");
}