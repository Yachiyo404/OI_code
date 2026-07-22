#include<bits/stdc++.h>
#define ll long long 
#define mem(a,m) memset(a,m,sizeof(a))
using namespace std;
ll n,m,a,b,c,d,t,rest_time[N],rest_power[N];
const ll N=2e5+10;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        rest_power[i]=read();
    for(ll o=1;o<=m;o++){
        a=read();
        b=read();
        c=read();
        d=read();
        t++;
        if(rest_power[b]>=d){
            rest_power[b]-=d;
            
        }
            
        
    }
    return 0;
}