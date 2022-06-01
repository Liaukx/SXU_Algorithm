#include<stdio.h>
#define N 1000
struct StNode
{
    int id;
    StNode* next = nullptr;
    StNode* pre = nullptr;
    StNode(int id):id(id){
        pre = nullptr;
        next = nullptr;
    }
};
void show(StNode * head){
    StNode* cur = head -> next;
    while ( cur != nullptr)
    {
       printf("%d ", cur -> id );
       cur = cur -> next;
    }
    return;
}
void Move(StNode* head,int id,int dir){
    if(!dir) return;
    StNode* cur = head -> next;
    while(cur -> id !=id){
        cur = cur -> next;
    }
    
    if(dir > 0){

        StNode* tar = cur -> next;
        cur -> pre -> next = cur -> next;
        if(cur -> next) cur -> next -> pre = cur -> pre;
        // printf("** %d **",cur -> id);

        for (int i = dir - 1 ; i > 0; --i){
            tar = tar -> next;
        }
        // printf("** %d **",tar -> id);
        //要作为tar 的后一个
        cur -> next = tar -> next;
        cur -> pre = tar;
        tar -> next = cur;
        if(cur -> next) cur -> next -> pre = cur;

    }else{

        StNode* tar = cur -> pre;
        cur -> pre -> next = cur -> next;
        if(cur -> next) cur -> next -> pre = cur -> pre;
        for(int i = dir+1; i < 0; ++ i){
            tar = tar -> pre;
        }
        //要作为tar 的前一个
        cur -> next = tar;
        cur -> pre = tar -> pre;
        tar -> pre = cur;
        cur -> pre -> next = cur;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    StNode * Head = new StNode(0);
    Head -> next = new StNode(1);
    Head -> next -> pre = Head;
    StNode * cur = Head -> next;
    for (int i = 2; i <= n; ++ i){
        cur -> next = new StNode(i);
        cur -> next -> pre = cur;
        cur = cur -> next;
    }
    // show(Head);
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; ++ i){
        int id,move;
        scanf("%d %d",&id,&move);
        Move(Head,id,move);
    }
    show(Head);
}
