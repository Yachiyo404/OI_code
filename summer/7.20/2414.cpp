#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,a,b,cnt,tot;
ll dfn[N],low[N];
bool ins[N],ise[N];//ise代表是否为割点
stack<ll> sta;
vector<ll> g[N],ans;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++cnt;
    sta.push(u);
    ins[u]=1;
    int cnt=0;
    for(int v:g[u]){
        if(v!=fa){
            if(!dfn[v]){
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
                cnt+=(low[v]>=dfn[u]);
            }
            else if(ins[v])
                low[u]=min(low[u],dfn[v]);
        }
    }
    if(u==a)
        ise[u]=cnt>1;
    else
        ise[u]=cnt>0;
    if(ise[u]&&dfn[u]<dfn[b]&&dfn[b]!=0)
        ans.push_back(u);
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
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i,i);
    }
    if(ans.empty())
        cout<<"No solution";
    else{
        sort(ans.begin(),ans.end());
        cout<<*(ans.begin());
    }
    return 0;
}