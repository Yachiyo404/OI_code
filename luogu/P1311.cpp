#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,k,p,now,ans;
ll cnt[N],sum[N],last[N];
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
    read(n),read(k),read(p);
    for(ll i=1;i<=n;i++){
        ll col,pri;
        read(col),read(pri);
        if(pri<=p)
            now=i;
        if(now>=last[col])
            sum[col]=cnt[col];
        last[col]=i;
        ans+=sum[col];
        cnt[col]++;
    }
    cout<<ans;
    return 0;
}