#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10,mod=1e10+7;
ll n,r,m;
ll size[N],cnt[N];
vector<ll> e[N];
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
inline void dfs(ll x,ll f){
    ll siz=e[x].size();
    for(ll i=0;i<siz;i++){
        if(e[x][i]!=f){
            dfs(e[x][i],x);
            cnt[x]=(cnt[x]+1ll*size[x]*size[e[x][i]])%mod;
            size[x]+=size[e[x][i]];
        }
    }
    cnt[x]=(cnt[x]+size[x])%mod;
    cnt[x]=cnt[x]*2%mod;
    size[x]++;
    cnt[x]++;
}
int main(){
    read(n),read(r),read(m);
    for(ll i=1;i<=n-1;i++){
        ll a,b;
        read(a),read(b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(r,0);
    while(m--){
        read(r);
        printf("%lld\n",cnt[r]);
    }
    return 0;
}