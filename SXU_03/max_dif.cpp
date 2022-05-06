#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    int ans = 0;
    cin >> N;
    vector<int> array;
    for(int i = 0; i< N; ++ i){
        int tmp;
        cin >> tmp;
        array.push_back(tmp);
    }
    for (int i = 0; i < array.size(); ++ i){
        for(int cur = i + 1; cur < array.size(); ++ cur){
            ans = array[i] - array[cur] > ans ?  array[i] - array[cur] : ans;
        }
    }
    cout << ans;
    return 0;
}