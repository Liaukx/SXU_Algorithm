#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool isBst(vector<int>& array ,int beg,int end){
    if(beg >= end) return true;
    int i = beg;
    //记录左子树
    while(array[i] < array[end]){
        ++ i;
    }
    //判断右子树 是否都比当前结点大
    for(i; i < end; ++ i){
        if(array[i] < array[end]) return false;
    }
    //递归的判断左右子树是否为BST
    return isBst(array,beg,i-1) & isBst(array,i,end-1);
}
int main(){
    vector<int> array;
    int tmp;
    while(cin.peek()!= EOF){
        cin >> tmp;
        array.push_back(tmp);
    }

    cout << (isBst(array,0,array.size()-1) ? "true" :"false");
    return 0; 
}
