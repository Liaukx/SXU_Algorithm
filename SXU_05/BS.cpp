#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
int A[500];
int n;
vector<int> path;
int BS(int *A,int beg,int end,int key){
    int mid = beg + ((end - beg) >> 1);
    if(mid == end && A[mid] != key){
        cout << "no" << endl;
        return -1;
    }
    path.push_back(A[mid]);
    if(A[mid] == key) return mid;
    if(A[mid] < key) return BS(A,mid + 1,end,key);
    return BS(A,beg,mid-1,key);
}
int main(){
    // int n ;
    cin >> n;
    for (int i = 0; i< n; ++ i){
        scanf("%d",A + i);
        // cout << A[i] << " ";
        getchar(); 
    }
    int key ;
    cin >> key;
    int index = BS(A,0,n-1,key);
    if(index != -1) cout << index << endl;
    for (int i = 0; i < path.size(); ++ i){
        if (i == path.size()-1){
            cout << path[i];
            break;
        }
        cout << path[i] << ",";
    }
   
    return 0;
}