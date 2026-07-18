#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2010;
int n,m;
struct edge{
    int v,w;
};
vector<edge> g[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    
    return 0;
}