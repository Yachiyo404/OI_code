#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+10;
ll n,m;
ll fa[N],emy[N];
struct node{
    ll data,x,y;
}peo[(int)1e5+10];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
inline ll find(ll x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
inline void cb(ll x,ll y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
inline bool check(ll x,ll y){
    if(find(x)==find(y))
        return 1;
    else
        return 0;
}
inline bool cmp(node a,node b){
    return a.data>b.data;
}
int main(){
    read(n),read(m);
    for(ll i=1;i<=n;i++)
        fa[i]=i;
    for(ll i=1;i<=m;i++)
        read(peo[i].x),read(peo[i].y),read(peo[i].data);
    stable_sort(peo+1,peo+m+1,cmp);
    bool flag=0;
    for(ll i=1;i<=m;i++){
        if(check(peo[i].x,peo[i].y)){
            flag=1;
            printf("%lld",peo[i].data);
            break;
        }
        else{
            if(!emy[peo[i].x])
                emy[peo[i].x]=peo[i].y;
            else
                cb(emy[peo[i].x],peo[i].y);
            if(!emy[peo[i].y])
                emy[peo[i].y]=peo[i].x;
            else
                cb(emy[peo[i].y],peo[i].x);
        }
    }
    if(!flag)
        printf("0");
    return 0;
}