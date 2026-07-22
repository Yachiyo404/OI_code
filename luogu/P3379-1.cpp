//倍增LCA

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1;
ll n,m,s;
ll fa[N][35],dep[N];
vector<ll> e[N];
bool vis[N];
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
template<typename T,typename ...T1> inline void rd(T &x,T1 &...y){read(x);read(y...);} 
inline void write(ll x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
inline void dfs(ll u,ll f){
    fa[u][0]=f;
    dep[u]=dep[f]+1;
    for(auto v:e[u]){
        if(v!=f)
            dfs(v,u);
    }
}
inline ll lca(ll u,ll v){
    if(dep[u]<dep[v])   
        swap(u,v);
    for(ll k=25;k>=0;k--){
        if(dep[fa[u][k]]>=dep[v])
            u=fa[u][k];
    }
    if(u==v)
        return u;
    for(ll k=25;k>=0;k--){
        if(fa[u][k]!=fa[v][k]){
            u=fa[u][k];
            v=fa[v][k];
        }
    }
    return fa[u][0];
}
int main(){
    read(n),read(m),read(s);
    for(ll i=1;i<n;i++){
        ll x,y;
        rd(x,y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(s,0);
    for(ll j=1;1<<j<=n;j++){
        for(ll k=1;k<=n;k++)
            fa[k][j]=fa[fa[k][j-1]][j-1];
    }
    for(ll i=1;i<=m;i++){
        ll u,v;
        read(u),read(v);
        write(lca(u,v));
        putchar('\n');
    }
    return 0;
}
