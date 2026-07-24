//重构树
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int n,m,q,cnt,tot;
int fa_d[N*2],p_w[N*2],dep[N*2],fa_l[N*2][25];
struct edge{
    int u,v,w;
};
vector<edge> e;
vector<int> g[N*2];
void init(){
    tot=n;
    for(int i=1;i<=2*n;i++)
        fa_d[i]=i;
}
int find(int x){
    if(fa_d[x]==x)
        return x;
    else
        return fa_d[x]=find(fa_d[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    fa_d[x]=y;
}
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    fa_l[u][0]=f;
    for(int v:g[u]){
        if(v!=f){
            dfs(v,u);
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])
        swap(x,y);
    for(int k=24;k>=0;k--){
        if(dep[fa_l[x][k]]>=dep[y])
            x=fa_l[x][k];
    }
    if(x==y)
        return x;
    for(int k=24;k>=0;k--){
        if(fa_l[x][k]!=fa_l[y][k]){
            x=fa_l[x][k];
            y=fa_l[y][k];
        }
    }
    return fa_l[x][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    sort(e.begin(),e.end(),[](edge a,edge b){return a.w<b.w;});
    for(auto i:e){
        int u=i.u,v=i.v,w=i.w;
        if(find(u)==find(v))
            continue;
        u=find(u),v=find(v);
        tot++;
        g[tot].push_back(u);
        g[tot].push_back(v);
        fa_d[u]=tot;
        fa_d[v]=tot;
        fa_d[tot]=tot;
        p_w[tot]=w;
    }
    dfs(tot,tot);
    for(int k=1;k<=24;k++){
        for(int i=1;i<=tot;i++)
            fa_l[i][k]=fa_l[fa_l[i][k-1]][k-1];
    }
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<p_w[lca(x,y)]<<'\n';
    }
    return 0;
}