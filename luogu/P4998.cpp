#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,k,ans,l,r;
ll home[N<<1],tmp[N<<1];
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
    read(n),read(k);
    ll Max=0,Min=1e7;
    for(ll i=1;i<=n;i++){
        ll a; 
        read(a);
        home[a+N]++;
    }
    for(ll i=0;i<=N+N;i++)
        tmp[0]+=home[i]*i;
    r=n;
    for(ll i=1;i<=N+N;i++){
        l+=home[i-1];
		tmp[i]=tmp[i-1]+l-r;
		r-=home[i];
    }
    sort(tmp,tmp+N+N+1);
    for(ll i=0;i<=k-1;i++)
        ans+=tmp[i];
    cout<<ans;
    return 0;
}