#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v,n,Max;

bool vis[110];
vector<ll> g[110];
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
inline void dfs(ll id,ll len){
    vis[id]=1;
    len++;
    ll siz=g[id].size();
    for(ll i=0;i<siz;i++){
        ll y=g[id][i];
        if(!vis[y])
            dfs(y,len);
        else if(siz==1&&vis[y]){
            Max=max(Max,len);
            return;
        }
    }
}
int main(){
    read(v),read(n);
    for(ll i=1;i<v;i++){
        ll u,v;
        read(u),read(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,0);
    ll ans;
    Max--;
    if(n<=Max)
        ans=n+1;
    else{
        n-=Max;
        ans=min(v,Max+1+n/2);
    }
    cout<<ans;
    return 0;
}