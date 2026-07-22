#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m;
ll num[N],sign[N],bit[N],ans[N];
struct node{
    ll l,r,pos;
}que[N];
inline bool cmp(const node &a,const node &b){
    return a.r<b.r;
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
    for(ll i=1;i<=n;i++)
        num[i]=read();
    m=read();
    for(ll i=1;i<=m;i++){
        que[i].l=read();
        que[i].r=read();
        que[i].pos=i;
    }
    sort(que+1,que+m+1,cmp);
    ll loc=1;
    for(ll i=1;i<=m;i++){
        for(ll j=loc;j<=que[i].r;j++){
            if(sign[num[j]])
                add(sign[num[j]],-1);
            add(j,1);
            sign[num[j]]=j;
        }
        loc=que[i].r+1;
        ans[que[i].pos]=ask(que[i].r)-ask(que[i].l-1);
    }
    for(ll i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}