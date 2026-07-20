#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int n,m,cnt,tot;
ll a[N],na[N];
ll dfn[N],low[N],col[N];
bool insta[N];
stack<int> sta;
vector<int> g[N],ng[N];
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    sta.push(u);
    insta[u]=1;
    for(int v:g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(insta[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        int now;
        tot++;
        do{
            now=sta.top();
            sta.pop();
            col[now]=tot;
            insta[now]=0;
        }while(now!=u);
    }
}
void dfs(int u){
    
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
    for(int i=1;i<=n;i++)
        na[col[i]]+=a[i];
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
    dfs(1);
    return 0;
}