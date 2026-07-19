#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
int n,m;
int dis[N],cnt[N],pre[N];//cnt表示进队次数,pre表示松弛前的u
bool vis[N];//vis表示是否在队内
struct edge{
    int v,w;
};
vector<edge> g[N];
void spfa(int s){
    queue<int> q;
    fill(dis+1,dis+n+1,INT_MAX);
    fill(vis+1,vis+n+1,0);
    fill(cnt+1,cnt+n+1,0);
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto e:g[u]){
            int v=e.v,w=e.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                // pre[v]=u;
                if(cnt[v]>=n){
                    cout<<"YES"<<'\n';
                    return;
                    // vector<int> ans;
                    // int lst=v,i=pre[v];
                    // ans.push_back(v);
                    // while(i!=lst){
                    //     ans.push_back(i);
                    //     i=pre[i];
                    // }
                    // ans.push_back(i);
                    // for(int num:ans)
                    //     cout<<num<<' ';
                    // exit(0);
                }
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    cout<<"NO"<<'\n';
    // exit(0);
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(auto &i:g)
            i.clear();
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            if(w>=0)
                g[v].push_back({u,w});
        }
        spfa(1);
    }
    return 0;
}