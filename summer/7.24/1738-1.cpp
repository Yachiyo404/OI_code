//倍增
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int n,m,q,cnt;
int fa_d[N];
int fa_l[N][25],dep[N],mx[N][25];//mx维护从节点u向上跳2^k次方的路径最大值
struct edge{
    int u,v,w;
};
struct node{
    int v,w;
};
vector<edge> e;
vector<node> g[N];
void init(){
    cnt=0;
    for(int i=1;i<=n;i++)
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
    for(auto i:g[u]){
        if(i.v!=f){
            mx[i.v][0]=i.w;
            dfs(i.v,u);
        }
    }
}
int lca(int x,int y){
    int ans=0;
    if(dep[x]<dep[y])
        swap(x,y);
    for(int k=24;k>=0;k--){
        if(dep[fa_l[x][k]]>=dep[y]){
            ans=max(ans,mx[x][k]);
            x=fa_l[x][k];
        }
    }
    if(x==y)
        return ans;
    for(int k=24;k>=0;k--){
        if(fa_l[x][k]!=fa_l[y][k]){
            ans=max({ans,mx[x][k],mx[y][k]});
            x=fa_l[x][k];
            y=fa_l[y][k];
        }
    }
    ans=max({ans,mx[x][0],mx[y][0]});
    return ans;
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
        merge(u,v);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        cnt++;
        if(cnt==n-1)
            break;
    }
    dfs(1,0);
    for(int k=1;k<=24;k++){
        for(int i=1;i<=n;i++){
            fa_l[i][k]=fa_l[fa_l[i][k-1]][k-1];
            mx[i][k]=max(mx[i][k-1],mx[fa_l[i][k-1]][k-1]);
        }
    }
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }
    return 0;
}