#include<iostream>
// #include<vector>
using namespace std;
int arr1[50],arr2[50];
int main(){
    int len1,len2;
    cin >> len1 >> len2;
    // arr1.resize(len1);
    // arr1.resize(len2);
    for(int i = 0; i < len1 ; ++ i) {
        cin >> arr1[i];
    }
    for(int i = 0; i < len2; ++ i){
        cin >> arr2[i];
    }
    int cur1 = 0, cur2 = 0;
    // int cur = 0;
    while (cur1 < len1 && cur2 < len2){
        
        while(cur1 < len1 && arr1[cur1] < arr2[cur2]){
            cout << arr1[cur1 ++] << " ";
        }
        while(cur2 < len2 && arr2[cur2] < arr1[cur1]){
            cout << arr2[cur2 ++ ] << " ";
        }
        if (cur1 < len1 && cur2 < len2 && arr1[cur1] == arr2[cur2]){
            // cout << " * ";
            cout << arr1[cur1] << " ";
            int tmp1 = cur1,tmp2=cur2;
            while(tmp1 < len1 && arr1[tmp1] == arr1[cur1]) ++ tmp1;
            while(tmp2 < len2 && arr2[tmp2] == arr1[cur1]) ++ tmp2;
            cur1 = tmp1;
            cur2 = tmp2;
        }
    }
    if(cur1 < len1 ){
        for(cur1; cur1 < len1; ++ cur1){
            cout << arr1[cur1] << " " ;
        }
    }
    if(cur2 < len2 ){
        for(cur2; cur2 < len2; ++ cur2){
            cout << arr2[cur2] << " " ;
        }
    }
}