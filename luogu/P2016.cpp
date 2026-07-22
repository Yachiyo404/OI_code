#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll dp[1510][2];
bool fa[1510],vis[1510];
vector<ll> g[1510];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
inline void dfs(ll x){
    vis[x]=1;
    dp[x][1]++;
    ll siz=g[x].size();
    for(ll i=0;i<siz;i++){
        ll y=g[x][i];
        if(!vis[y])
            dfs(y);
        else
            continue;
        dp[x][0]+=dp[y][1];
        dp[x][1]+=min(dp[y][0],dp[y][1]);
    }
}
int main(){
    read(n);
    for(ll i=1;i<=n;i++){
        ll id,k;
        read(id),read(k);
        for(ll j=1;j<=k;j++){
            ll v;
            read(v);
            fa[v]=1;
            g[id].push_back(v);
            g[v].push_back(id);
        }
    }
    ll root;
    for(ll i=0;i<=n-1;i++){
        if(!fa[i]){
            root=i;
            break;
        }
    }
    dfs(root);
    cout<<min(dp[root][0],dp[root][1]);
    return 0;
}