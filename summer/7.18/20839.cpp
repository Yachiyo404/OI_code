#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,ans=LLONG_MAX;
ll siz[N],dis[N],sum[N];
vector<ll> g[N];
void dfs_init(ll u,ll f){
    siz[u]=1;
    for(int v:g[u]){
        if(v!=f){
            dis[v]=dis[u]+1;
            dfs_init(v,u);
            siz[u]+=siz[v];
        }
    }
}
void dfs_cal(ll u,ll f){
    for(int v:g[u]){
        if(v!=f){
            sum[v]=sum[u]-siz[v]+n-siz[v];
            dfs_cal(v,u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_init(1,0);
    for(ll i=1;i<=n;i++)
        sum[1]+=dis[i];
    dfs_cal(1,0);
    for(ll i=1;i<=n;i++)
        ans=min(ans,sum[i]);
    cout<<ans;
    return 0;
}