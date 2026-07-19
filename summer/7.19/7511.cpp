#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,m;
ll dis[N];
bool vis[N];
struct edge{
    ll v,w;
    bool operator<(const edge &other)const{
        return w>other.w;
    }
};
vector<edge> g[N];
void dij(){
    priority_queue<edge> pq;
    fill(dis+1,dis+n+1,LLONG_MAX);
    dis[1]=0;
    pq.push((edge){1,0});
    while(!pq.empty()){
        ll u=pq.top().v;
        pq.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(auto e:g[u]){
            ll v=e.v,w=e.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push((edge){v,dis[v]});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back((edge){v,w});
    }
    dij();
    for(ll i=1;i<=n;i++){
        if(dis[i]!=LLONG_MAX)
            cout<<dis[i]<<' ';
        else
            cout<<"inf"<<' ';
    }
    return 0;
}