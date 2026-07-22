//并查集求LCA

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,s;
ll fa[N],ans[N];
bool vis[N];
vector<ll> g[N];
vector<pair<ll,ll>> ask[N];
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
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(ll x,ll y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
inline void lca(ll x){
    vis[x]=1;
    for(ll i=0;i<g[x].size();i++){
        ll v=g[x][i];
        if(vis[v])
            continue;
        lca(v);
        merge(v,x);
    }
    for(ll i=0;i<ask[x].size();i++){
        ll y=ask[x][i].first;
        ll id=ask[x][i].second;
        if(vis[y])
            ans[id]=find(y);
    }
}
int main(){
    read(n),read(m),read(s);
    for(ll i=1;i<n;i++)
        fa[i]=i;
    for(ll i=1;i<n;i++){
        ll x,y;
        read(x),read(y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(ll i=1;i<=m;i++){
        ll a,b;
        read(a),read(b);
        if(a==b)
            ans[i]=a;
        else{
            ask[a].push_back({b,i});
            ask[b].push_back({a,i});
        }
    }
    lca(s);
    for(ll i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}