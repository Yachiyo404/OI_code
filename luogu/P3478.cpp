#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#define mem(a,x) memset(a,x,sizeof(a))
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=gc();
    }
    return x*f;
}
inline void write(ll a){
    if(a<0){
        pc('-');
        a=-a;
    }
    if(a>9)
        write(a/10);
    pc(a%10+'0');
}
const int N=1e6+10;
ll n,sum;
ll size[N],ans[N];
vector<ll> tree[N];
bool vis[N];
inline void dfs1(ll id,ll dep){
    size[id]=1;
    vis[id]=1;
    if(tree[id].size()==1&&vis[tree[id][0]]){
        sum+=dep;
        return;
    }
    ll siz=tree[id].size();
    up(i,0,siz-1){
        ll cur=tree[id][i];
        if(!vis[cur]){
            dfs1(cur,dep+1);
            size[id]+=size[cur];
        }
    }
}
inline void dfs2(ll id){
    vis[id]=1;
    ll siz=tree[id].size();
    up(i,0,siz-1){
        ll cur=tree[id][i];
        if(!vis[cur]){
            ans[cur]=ans[id]+size[1]-2*size[cur];
            dfs2(cur);
        }
    }
}
int main(){
    n=read();
    up(i,1,n-1){
        ll u=read(),v=read();
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    dfs1(1,0);
    ans[1]=sum;
    mem(vis,0);
    dfs2(1);
    ll Max=0,id;
    up(i,1,n){
        if(Max<ans[i]){
            id=i;
            Max=ans[i];
        }
    }
    write(id);
    return 0;
}