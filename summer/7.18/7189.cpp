#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=310;
int n,m,ans=-1;
int add[N],f[N][N],siz[N];
vector<int> g[N],root;
void dfs(int u){
    f[u][1]=add[u];
    siz[u]=1;
    for(int v:g[u]){
        dfs(v);
        for(int j=siz[u]+siz[v];j>=1;j--){
            for(int k=1;k<=min(siz[v],j-1);k++)
                f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]);
        }
        siz[u]+=siz[v];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        int u,w;
        cin>>u>>w;
        if(u)
            g[u].push_back(i);
        else
            root.push_back(i);
        add[i]=w;
    }
    add[0]=0;
    for(int r:root)
        g[0].push_back(r);
    dfs(0);
    cout<<f[0][n+1];
    return 0;
}