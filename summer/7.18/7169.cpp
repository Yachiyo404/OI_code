#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int n;
int dis[N];
struct edge{
    int v,w;
};
vector<edge> g[N];
void dfs(int u,int f){
    for(auto e:g[u]){
        int v=e.v,w=e.w;
        if(v!=f){
            dis[v]=dis[u]+w;
            dfs(v,u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    dfs(1,0);
    int s,len=-1;
    for(int i=1;i<=n;i++){
        if(len<dis[i]){
            len=dis[i];
            s=i;
        }
    }
    for(int i=1;i<=n;i++)
        dis[i]=0;
    dfs(s,0);
    len=-1;
    for(int i=1;i<=n;i++)
        len=max(len,dis[i]);
    cout<<len;
    return 0;
}