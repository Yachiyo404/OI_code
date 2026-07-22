//ST表求LCA

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1;
ll n,m,r,dn;
ll dfn[N],mi[20][N];
vector<ll> e[N];
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
inline ll get(ll x,ll y){
    if(dfn[x]<dfn[y])
        return x;
    else
        return y;
}
inline ll lg(ll x){
    ll res=0;
    while(x>>=1)
        res++;
    return res;
}
inline void dfs(ll id,ll f){
    dn++;
    dfn[id]=dn;
    mi[0][dfn[id]]=f;
    for(ll it:e[id]){
        if(it!=f)
            dfs(it,id);
    }
}
inline ll lca(ll u,ll v){
    if(u==v)
        return u;
    u=dfn[u];
    v=dfn[v];
    if(u>v)
        swap(u,v);
    ll d=lg(v-u);
    u++;
    return get(mi[d][u],mi[d][v-(1<<d)+1]);
}
int main(){
    read(n),read(m),read(r);
    for(ll i=1;i<=n-1;i++){
        ll a,b;
        read(a),read(b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(r,0);
    for(ll i=1;i<=lg(n);i++){
        for(ll j=1;j+(1<<i)-1<=n;j++)
            mi[i][j]=get(mi[i-1][j],mi[i-1][j+(1<<i-1)]);
    }
    for(ll i=1;i<=m;i++){
        ll u,v;
        read(u),read(v);
        printf("%lld\n",lca(u,v));
    }
    return 0;
}