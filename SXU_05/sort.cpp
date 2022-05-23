#include<iostream>
using namespace std;
int array[100];
void show(int* a,int len){
    for (int i = 0; i < len; ++ i){
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}
void solve(int* a,int len){
    // 插入排序
    // show(a,len);
    for (int cur = 1; cur < len; ++  cur){
        int key=a[cur];
        int tmp = cur -1;

        // cout << a[tmp+1]<< ":" << a[tmp];
        while(tmp >= 0 && a[tmp] > key) {
            a[tmp + 1] = a[tmp];
            tmp --;
        }
        if(tmp!=cur-1)a[tmp + 1] = key;
        show(a,len);
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i< n; ++ i){
        cin >> array[i];
    }
    solve(array,n);
}