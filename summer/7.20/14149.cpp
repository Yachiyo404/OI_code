#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,m,tot,t;
ll ans;
ll dfn[N],low[N],col[N],cnt[N],in[N];
bool ins[N],vis[N];
vector<ll> g[N],ng[N];
stack<ll> sta;
void tarjan(ll u){
    dfn[u]=low[u]=++t;
    sta.push(u);
    ins[u]=1;
    for(ll v:g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ll now;
        tot++;
        do{
            now=sta.top();
            sta.pop();
            col[now]=tot;
            ins[now]=0;
            cnt[tot]++;
        }while(now!=u);
    }
}
void topsort(ll s){
    queue<ll> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:ng[u]){
            if(!vis[v]){
                in[v]--;
                ans++;
                if(!in[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(ll i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    for(ll u=1;u<=n;u++){
        for(ll v:g[u]){
            if(col[u]!=col[v])
                ng[col[u]].push_back(col[v]);
        }
    }
    for(ll i=1;i<=tot;i++){
        sort(ng[i].begin(),ng[i].end());
        ng[i].erase(unique(ng[i].begin(),ng[i].end()),ng[i].end());
    }
    for(int i=1;i<=tot;i++){
        if(cnt[i]>1)
            ans+=cnt[i];
    }
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<' ';
    // cout<<endl;
    for(ll u=1;u<=tot;u++){
        for(ll v:ng[u])
            in[v]++;
    }
    for(ll i=1;i<=tot;i++){
        if(!in[i]&&!vis[i])
            topsort(i);
    }
    cout<<ans;
    return 0;
}