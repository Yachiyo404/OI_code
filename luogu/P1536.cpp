#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=1,m,s,e,ans;
ll fa[201000];
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
int main(){
    while(1){
        n=read();
        if(n==0)
            break;
        m=read();
        for(ll i=1;i<=n;i++)
            fa[i]=i;
        for(ll i=1;i<=m;i++){
            s=read();e=read();
            if(find(s)==find(e))
                continue;
            merge(s,e);
        }
        for(ll i=1;i<=n;i++){
            if(i==fa[i])
                ans++;
        }
        printf("%lld\n",ans-1);
        ans=0;
    }
    return 0;
}