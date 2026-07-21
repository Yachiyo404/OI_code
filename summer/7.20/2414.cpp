#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a,b,cnt,tot;
ll dfn[N],low[N];
bool ins[N];//ise代表是否为割点
stack<ll> sta;
vector<ll> g[N],ans;
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    sta.push(u);
    for(int v:g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]&&dfn[v]<=dfn[b]&&u!=a)
                ans.push_back(u);
        }
        else 
            low[u]=min(low[u],dfn[v]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    while(1){
        int u,v;
        cin>>u>>v;
        if(u==0&&v==0)
            break;
        else{
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    cin>>a>>b;
    tarjan(a);
    if(ans.empty())
        cout<<"No solution";
    else{
        sort(ans.begin(),ans.end());
        cout<<*(ans.begin());
    }
    return 0;
}