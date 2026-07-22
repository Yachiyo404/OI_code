#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
ll n,m,cnt;
ll num[N],bit[N];
struct node{
    ll cute,pos;
}fish[N];
inline bool cmp(node a,node b){
    return a.cute<b.cute;
}
inline ll read(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
inline ll lowbit(ll x){
    return x&-x;
}
inline ll ask(ll x){
    ll sum=0;
    while(x){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
inline void add(ll x,ll y){
    while(x<=n){
        bit[x]+=y;
        x+=lowbit(x);
    }
}
int main(){
    n=read();
    for(ll i=1;i<=n;i++){
        fish[i].cute=read();
        fish[i].pos=i;
    }
    stable_sort(fish+1,fish+n+1,cmp);
    for(ll i=1;i<=n;i++){
        if(fish[i].cute==fish[i-1].cute)
            fish[i-1].cute=-1;
    }
    for(ll i=n;i>=1;i--){
        if(fish[i].cute==-1)
            num[fish[i].pos]=num[fish[i+1].pos];
        else
            num[fish[i].pos]=i;
    }
    /*for(ll i=1;i<=n;i++)
        cout<<num[i]<<" ";
    cout<<endl;*/
    for(ll i=1;i<=n;i++){
        add(num[i],1);
        cnt=ask(num[i]-1);
        printf("%lld ",cnt);
    }
    return 0;
}