#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,x;
ll num[N],f[N];
unordered_map<ll,ll> lst;
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
int main(){
    read(n),read(m),read(x);
    for(ll i=1;i<=n;i++){
        read(num[i]);
        lst[num[i]]=i;
        f[i]=max(f[i-1],lst[num[i]^x]);
    }
    for(ll i=1;i<=m;i++){
        ll l,r;
        read(l),read(r);
        if(f[r]<l)
            puts("no");
        else
            puts("yes");
    }
    return 0;
}