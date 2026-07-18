#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2010;
ll n,m;
ll f[N][N],siz[N];
struct edge{
    ll v,w;
};
vector<edge> g[N];
void dfs_init(ll u,ll fa){
    siz[u]=1;
    for(auto e:g[u]){
        ll v=e.v,w=e.w;
        if(v!=fa){
            dfs_init(v,u);
            siz[u]+=siz[v];
        }
    }
}
void dfs_cla(ll u,ll fa){
    for(auto e:g[u]){
        ll v=e.v,w=e.w;
        if(v!=fa){
            dfs_cla(v,u);
            for(ll j=siz[u];j>=1;j--){
                for(ll k=0;k<=min(siz[v],j-1);k++){
                    ll cnt=k*(m-k)+(siz[v]-k)*(n-m-siz[v]+k);
                    f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]+cnt*w);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=1;i<=n-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs_init(1,0);
    dfs_cla(1,0);
    cout<<f[1][m];
    return 0;
}