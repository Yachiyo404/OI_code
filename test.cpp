#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,cnt,tot;
int dfn[N<<1],low[N<<1],col[N<<1];
bool ins[N<<1];
vector<int> g[N<<1];
stack<int> sta;
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
    while(m--){
        int i,j,a,b;
        cin>>i>>a>>j>>b;
        if(a&b){
            g[i+n].push_back(j);
            g[j+n].push_back(i);
        }
        else if(a&!b){
            g[i+n].push_back(j+n);
            g[j].push_back(i);
        }
        else if(!a&b){
            g[i].push_back(j);
            g[j+n].push_back(i+n);
        }
        else{
            
        }
    }
    return 0;
}