#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,sum,cnt;
int fa_d[N],fa_l[N][25],dep[N],mx1[N][25],mx2[N][25];
struct edge{
    int u,v,w;
    bool used;
};
vector<edge> e;
vector<pair<int,int>> g[N];
void init(){
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
pair<int,int> comb(int a,int b,int c,int d){
    vector<int> v={a,b,c,d};
    sort(v.begin(),v.end(),[](int a,int b){return a>b;});
    
}
void dfs(int u,int f,int w){
    fa_l[u][0]=f;
    mx1[u][0]=w;
    mx2[u][0]=-1;
    dep[u]=dep[f]+1;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w,0});
    }
    sort(e.begin(),e.end(),[](edge a,edge b){return a.w<b.w;});
    for(auto &i:e){
        int u=i.u,v=i.v,w=i.w;
        u=find(u),v=find(v);
        if(u==v)
            continue;
        sum+=w;
        i.used=1;
        merge(u,v);
        g[i.u].push_back({i.v,w});
        g[i.v].push_back({i.u,w});
        if(cnt==n-1)
            break;
    }
    return 0;
}