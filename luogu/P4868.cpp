#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,m;
ll a[N],bit1[N],bit2[N];
inline ll read(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
inline ll lowbit(ll x){
    return x&-x;
}
inline void add(ll *tree,ll x,ll y){
    while(x<=n){
        tree[x]+=y;
        x+=lowbit(x);
    }
    return;
}
inline ll ask(ll *tree,ll x){
    ll sum=0;
    while(x){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}
int main(){
    n=read(),m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
        add(bit1,i,a[i]);
        add(bit2,i,i*a[i]);
    }
    while(m--){
        char str[10];
        ll i,x;
        scanf("%s",&str);
        if(str[0]=='M'){
            i=read(),x=read();
            add(bit1,i,x-a[i]);
            add(bit2,i,i*(x-a[i]));
            a[i]=x;
        }
        else{
            i=read();
            ll ans=(i+1)*ask(bit1,i)-ask(bit2,i);
            printf("%lld\n",ans);
        }
    }
    return 0;
}