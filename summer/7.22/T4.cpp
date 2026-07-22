#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+10,mod=998244353;
ll T,n,m,k,x,sum;
ll out[N];
bool vis[N];
vector<int> g[N];
void dfs(int u,bool f,int cnt,int lst){
    ll tot=0;
    vis[u]=1;
    for(int v:g[u]){
        if(!vis[v]){
            if(f){
                for(int i=1;i<=k-1;i++){
                    vis[v]=1;
                    dfs(v,0,cnt,i);
                    tot++;
                    vis[v]=0;
                }
            }
            else{
                for(int i=1;i<=m;i++){
                    if(i==k&&cnt<x&&lst<k){
                        vis[v]=1;
                        dfs(v,1,cnt+1,i);
                        tot++;
                        vis[v]=0;
                    }
                    else{
                        vis[v]=1;
                        dfs(v,0,cnt,i);
                        tot++;
                        vis[v]=0;
                    }
                }
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    // freopen("forest.in","r",stdin);
    // freopen("forest.out","w",stdout);
    cin>>T;
    while(T--){
        ll ans=LLONG_MIN;
        cin>>n>>m>>k>>x;
        for(auto &i:g)
            i.clear();
        fill(vis+1,vis+n+1,0);
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            out[u]++;
            out[v]++;
        }
        sum=0;
        dfs(1,0,0,m+1);
        ans=max(ans,sum);
        sum=0;
        dfs(1,1,1,m+1);
        ans=max(ans,sum);
        cout<<ans<<endl;
    }
    return 0;
}