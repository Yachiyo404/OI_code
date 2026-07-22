#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e3+10,mod=998244353;
ll T,n,m,k,x;
ll dp[N][N][3],siz[N],tmp[N][3];//dp[u][i][c]表示以u为根的子树中使用k的点有i个，根u点状态为c
bool vis[N];
vector<ll> g[N];
void init(){
    fill(vis+1,vis+n+1,0);
    for(auto &i:g)
        i.clear();
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=x;j++)
            dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=0;
    }
    for(ll i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void dfs(ll u,ll f){
    siz[u]=1;
    dp[u][0][0]=k-1;
    dp[u][1][1]=1;
    dp[u][0][2]=m-k;
    for(ll v:g[u]){
        if(v!=f){
            dfs(v,u);
            for(ll i=0;i<=min(siz[u]+siz[v],x);i++)
                tmp[i][0]=tmp[i][1]=tmp[i][2]=0;
            for(ll i=0;i<=min(siz[u],x);i++){
                if(!dp[u][i][0]&&!dp[u][i][1]&&!dp[u][i][2])
                    continue;
                for(ll j=0;j<=min(siz[v],x-i);j++){
                    ll tmpv1=(dp[v][j][0]+dp[v][j][1]+dp[v][j][2])%mod;
                    ll tmpv2=(dp[v][j][0]+dp[v][j][2])%mod;
                    tmp[i+j][0]=(tmp[i+j][0]+dp[u][i][0]*tmpv1)%mod;
                    tmp[i+j][1]=(tmp[i+j][1]+dp[u][i][1]*dp[v][j][0])%mod;
                    tmp[i+j][2]=(tmp[i+j][2]+dp[u][i][2]*tmpv2)%mod;
                }
            }
            siz[u]+=siz[v];
            for(ll i=0;i<=min(siz[u],x);i++){
                dp[u][i][0]=tmp[i][0];
                dp[u][i][1]=tmp[i][1];
                dp[u][i][2]=tmp[i][2];
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    // freopen("forest.in","r",stdin);
    // freopen("forest.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x;
        init();
        dfs(1,0);
        ll ans=0;
        for(ll i=0;i<=x;i++)
            ans=(ans+dp[1][i][0]+dp[1][i][1]+dp[1][i][2])%mod;
        cout<<ans<<'\n';
    }
    return 0;
}