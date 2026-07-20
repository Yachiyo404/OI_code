#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int n,m,cnt,tot;
ll a[N],new_a[N],dp[N];//点权及dp数组
ll dfn[N],low[N],col[N];//tarjan
ll in[N];//top sort
bool ins[N];
stack<ll> sta;
vector<ll> g[N],ng[N];
void tarjan(ll u){
    dfn[u]=low[u]=++cnt;
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
            new_a[tot]+=a[now];
        }while(now!=u);
    }
}
void topsort(){
    queue<ll> q;
    for(int i=1;i<=tot;i++){
        if(in[i])
            dp[i]=LLONG_MIN;
        else{
            dp[i]=new_a[i];
            q.push(i);
        }
    }
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        for(ll i:ng[now]){
            dp[i]=max(dp[i],dp[now]+new_a[i]);
            in[i]--;
            if(!in[i])
                q.push(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    for(int u=1;u<=n;u++){
        for(int v:g[u]){
            if(col[u]!=col[v])
                ng[col[u]].push_back(col[v]);
        }
    }
    for(int u=1;u<=tot;u++){
        sort(ng[u].begin(),ng[u].end());
        ng[u].erase(unique(ng[u].begin(),ng[u].end()),ng[u].end());
    }
    for(int i=1;i<=tot;i++){
        for(int j:ng[i])
            in[j]++;
    }
    topsort();
    ll ans=LLONG_MIN;
    for(int i=1;i<=tot;i++)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}