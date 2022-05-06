#include <iostream>
using namespace std;
void solve(int n){
    bool flag = false;
    for (int i = 1; i <= n/2; ++ i ){
        for(int k = 1; k < n/i + 1; ++ k ){
            if(k * i + (k *(k - 1))/2 == n){
                flag = true;
               for (int cur = 0; cur < k; ++ cur){
                   if(cur == k -1) cout << i + cur << endl;
                   else cout << i + cur << " ";
               }
            }if(k * i + (k *(k - 1))/2 > n){
                break;
            }
        }
    }
    if (!flag){
        cout << "NONE" << endl;
    }
}
int main(){
    int N;
    cin >> N;
    solve(N);
    return 0;
}