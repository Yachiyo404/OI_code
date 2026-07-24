#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,q,cnt,tot;
ll dfn[N],low[N],col[N];//tarjan
bool ins[N];//tarjan
ll check[N],dis[N];
bool vis[N];
struct edge{
    ll v,w;
};
vector<edge> g[N];
stack<ll> sta;
void tarjan(ll u){
    dfn[u]=low[u]=++cnt;
    sta.push(u);
    ins[u]=1;
    for(auto e:g[u]){
        int v=e.v;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        int now;
        tot++;
        do{
            now=sta.top();
            sta.pop();
            col[now]=tot;
            ins[now]=0;
        }while(now!=u);
    }
}
void dfs(ll u,ll id){
    
}
signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(ll i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        ll u=(a%n+n)%n,v=(a%n+n)%n;
        g[u].push_back({v,b});
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }

    return 0;
}