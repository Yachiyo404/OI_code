#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int mod=80112002;
ll n,m,ans;
ll in[N],out[N],cnt[N];
vector<ll> g[N];
queue<ll> q;
inline ll read(){
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
    return x*f;
}
int main(){
    n=read(),m=read();
    for(ll i=1;i<=m;i++){
        ll a=read(),b=read();
        g[a].push_back(b);
        out[a]++;
        in[b]++;
    }
    for(ll i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
            cnt[i]=1;
        }
    }
    while(q.size()){
        ll now=q.front(),size=g[now].size();
        q.pop();
        for(ll i=0;i<=size-1;i++){
            ll next=g[now][i];
            in[next]--;
            cnt[next]=(cnt[now]+cnt[next])%mod;
            if(!in[next])
                q.push(next);
        }
    }
    for(ll i=1;i<=n;i++){
        if(!out[i])
            ans=(ans+cnt[i])%mod;
    }
    printf("%lld",ans);
    return 0;
}