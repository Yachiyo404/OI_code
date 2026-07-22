#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,cnt;
ll fa[5005];
struct node{
    ll u,v,w;
}G[200010];
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
bool cmp(node a,node b){
    return a.w<b.w;
}
inline void init(){
    for(ll i=1;i<=n;i++)
        fa[i]=i;
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
    ll sum=0;
    sort(G+1,G+m+1,cmp);
    init();
    for(ll i=1;i<=m;i++){
        ll u=G[i].u,v=G[i].v;
        if(find(u)==find(v))
            continue;
        merge(u,v);
        sum+=G[i].w;
        cnt--;
    }
    if(cnt==1)
        return sum;
    else
        return -1;
}
int main(){
    n=read();m=read();
    for(ll i=1;i<=m;i++){
        G[i].u=read();
        G[i].v=read();
        G[i].w=read();
    }
    ll ans=kru();
    if(ans==-1)
        cout<<"orz";
    else
        cout<<ans;
    return 0;
}