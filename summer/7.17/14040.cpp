#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m;
int fa[N][20],dep[N],lg2[N],d[N];
vector<int> g[N];
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for(int i=1;i<=lg2[dep[u]];i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto i:g[u]){
        if(i!=f)
            dfs(i,u);
    }
}
void dfs_calc(int u,int f){//修改完进行统一的计算，从下向上回溯
    for(int i:g[u]){
        if(i!=f){
            dfs_calc(i,u);
            d[u]+=d[i];
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])
        swap(x,y);
    for(int k=19;k>=0;k--){
        if(dep[fa[x][k]]>=dep[y])
            x=fa[x][k];
    }
    if(x==y)
        return x;
    for(int k=19;k>=0;k--){
        if(fa[x][k]!=fa[y][k]){
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
void init(){
    lg2[1]=0;
    for(int i=2;i<=n;i++)
        lg2[i]=lg2[i>>1]+1;
    dfs(1,0);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    for(int i=1;i<=m;i++){
        int s,t;
        cin>>s>>t;
        int f=lca(s,t);
        d[f]--;
        if(fa[f][0])
            d[fa[f][0]]--;
        d[s]++;
        d[t]++;
    }
    dfs_calc(1,0);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<' ';
    return 0;
}