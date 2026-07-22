#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
ll n,t;
ll num[N<<1];
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
inline bool check(ll x){
    for(ll r=x;r<=n;++r){
        ll l=r-x+1;
        if(num[r]<=0){
            if(-num[l]<=t)
                return 1;
        }
        if(num[l]>=0){
            if(num[r]<=t)
                return 1;
        }
        if(num[l]<=0&&num[r]>=0){
		    if(min(num[r],-num[l])+num[r]-num[l]<=t)
                return 1;
        }
    }
    return 0;
}
int main(){
    read(t),read(n);
    for(ll i=1;i<=n;++i)
        read(num[i]);
    sort(num+1,num+n+1);
    ll l=0,r=n+1;
    while(l+1<r){
        ll mid=(l+r)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<l;
    return 0;
}