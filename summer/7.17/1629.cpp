#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e4+10;
int n,q;
int fa[N][20],dep[N],lg2[N],r[N];
vector<int> g[N];
ll ans;
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
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lg2[1]=0;
    for(int i=2;i<=N;i++)
        lg2[i]=lg2[i>>1]+1;
    dfs(1,0);
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>r[i];
        if(i>1){
            int mid=lca(r[i],r[i-1]);
            ans+=(dep[r[i]]+dep[r[i-1]]-dep[mid]*2);
        }
    }
    cout<<ans;
    return 0;
}