#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e3+10;
ll n;
ll f[N][2],h[N],v[N];
vector<ll> son[N];
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
inline void dp(ll x){
    f[x][0]=0;
    f[x][1]=h[x];
    ll siz=son[x].size();
    for(ll i=0;i<siz;i++){
        ll y=son[x][i];
        dp(y);
        f[x][0]+=max(f[y][0],f[y][1]);
        f[x][1]+=f[y][0];
    }
}
int main(){
    read(n);
    for(ll i=1;i<=n;i++)
        read(h[i]);
    for(ll i=1;i<=n-1;i++){
        ll x,y;
        read(x),read(y);
        son[y].push_back(x);
        v[x]=1;
    }
    ll root;
    for(ll i=1;i<=n;i++){
        if(!v[i]){
            root=i;
            break;
        }
    }
    dp(root);
    printf("%lld",max(f[root][0],f[root][1]));
    return 0;
}