#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+10;
ll n,m,cnt;
ll fa[1005];
struct node{
    ll u,v,t;
}G[N];
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
inline bool cmp(node a,node b){
    return a.t<b.t;
}
inline ll find(ll x){
    if(x==fa[x])
        return x;
    return fa[x]=find(fa[x]);
}
inline void merge(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    fa[x]=y;
}
inline ll kru(){
    cnt=n;
    sort(G+1,G+m+1,cmp);
    for(ll i=1;i<=n;i++)
        fa[i]=i;
    for(ll i=1;i<=m;i++){
        ll u=G[i].u,v=G[i].v;
        if(find(u)==find(v))
            continue;
        merge(u,v);
        cnt--;
        if(cnt==1)
            return G[i].t;
    }
    return -1;
}
int main(){
    n=read();m=read();
    for(ll i=1;i<=m;i++){
        G[i].u=read();
        G[i].v=read();
        G[i].t=read();
    }
    ll ans=kru();
    printf("%lld",ans);
    return 0;
}