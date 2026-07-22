#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6;
ll n,m,cnt,p;
ll fa[505];
struct node{
    ll u,v,w;
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
    return a.w<b.w;
}
inline ll find(ll x){
    if(fa[x]==x)
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
    sort(G+1,G+n+1,cmp);
    for(ll i=1;i<=n;i++){
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
    p=read();n=read();
    for(ll i=1;i<=n;i++)
        fa[i]=i;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            
            
            
        }
    }
    return 0;
}