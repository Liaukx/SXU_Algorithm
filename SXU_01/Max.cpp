#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n;++ i){
        int tmp;
        cin >> tmp;
        if(i == 0){
            ans = tmp;
            continue;
        }
        ans = ans > tmp ? ans : tmp;
    }
    cout << ans;
    return 0;
}