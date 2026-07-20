#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,cnt,tot;
int dfn[N],low[N],col[N];
bool ins[N];
stack<int> sta;
vector<int> g[N];
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    sta.push(u);
    ins[u]=1;
    for(int v:g[u]){
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
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            while(!sta.empty())
                sta.pop();
            cnt=0;
            tarjan(i);
        }
    }
    cout<<tot<<'\n';
    for(int i=1;i<=n;i++)
        cout<<col[i]<<' ';
    return 0;
}