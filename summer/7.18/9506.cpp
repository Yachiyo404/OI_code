#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int r[N],f[N][2];
vector<int> g[N];
void dfs(int u,int fa){
    f[u][1]=r[u];
    for(int v:g[u]){
        if(v!=fa){
            dfs(v,u);
            f[u][0]+=max(f[v][0],f[v][1]);
            f[u][1]+=f[v][0];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<max(f[1][1],f[1][0]);
    return 0;
}