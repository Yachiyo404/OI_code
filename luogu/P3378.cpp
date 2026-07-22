#include<bits/stdc++.h>
#define ll long long
#define mem(a,m) memset(a,m,sizeof(a))
using namespace std;
ll n,num,new_heap[1000005],siz,op;
void push(ll x){//入堆
    new_heap[++siz]=x;//将新元素放在堆底
    ll son=siz;
    while(son>1){//在到达堆顶之前不停
        ll father=son/2;//求父亲节点
        if(new_heap[father]>new_heap[son])
            swap(new_heap[father],new_heap[son]);
        else
            break;//符合堆的规则
        son=father;//上移
    }
    return;
}
void pop(){
    swap(new_heap[1],new_heap[siz]);
    siz--;//弹掉堆顶
    ll father=1;
    while(father*2<=siz){
        ll son=father*2;
        if(son+1<=siz&&new_heap[son+1]<new_heap[son])
            son++;//很重要！千万不要忘记比较左孩子与右孩子的大小，否则会变得不幸
        if(new_heap[father]>new_heap[son])
            swap(new_heap[father],new_heap[son]);
        else    
            break;//符合堆的规则
        father=son;//下移
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>op;
        switch(op){
            case 1:
                cin>>num;
                push(num);
                break;
            case 2:
                cout<<new_heap[1]<<endl;
                break;
            case 3:
                pop();
        }
    }
    return 0;
}