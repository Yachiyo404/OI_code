#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
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
const int N=1e4+10;
ll n,m,k;
struct edge{
    ll u,v,w_e,w_p;
};
vector<edge> g;
vector<ll> c_pri,town[N];
bool flag[15],vis[15];
ll fa[N];
inline ll find(ll x){
    if(x==fa[x])
        return x;
    return fa[x]=find(fa[x]);
}
inline void merge(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    fa[x]=y;
}
inline ll kru(){
    
}
inline void dfs(ll dep){
    if(dep>=k+1){
        up(i,1,k){
            
        }
    }
    up(i,0,1){
        if(!vis[dep+1]){
            vis[dep+1]=1;
            if(i)
                flag[dep+1]=i;
            else
                flag[dep+1]=i;
            dfs(dep+1);
            vis[dep+1]=0;
        }
    }
}
int main(){
    n=read(),m=read(),k=read();
    up(i,1,m){
        ll u=read(),v=read(),w=read();
        g.emplace_back((edge){u,v,w,0});
    }
    up(i,1,k){
        ll c=read();
        c_pri.emplace_back(c);
        up(j,1,n){
            ll w=read();
            town[j].emplace_back(w);
        }
    }
    dfs(0);

    
    return 0;
}