#include<iostream>
using namespace std;
int main(){
    int n , tar;
    cin >> n >> tar;
    for(int i = 0; i < n;++ i){
        int tmp;
        cin >> tmp;
        if(tmp == tar){
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}