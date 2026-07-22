#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,cnt;
bool flag;
ll num[N],bit[N];
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
inline ll ask(ll x){
    ll sum=0;
    while(x){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
inline void add(ll x,ll y){
    while(x<=n){
        bit[x]+=y;
        x+=lowbit(x);
    }
}
int main(){
    n=read();
    m=read();
    for(ll i=1;i<=n;i++){
        num[i]=read();
        if(num[i]<num[i-1])
            flag=1;
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    for(ll i=n;i>=1;i--){
        cnt+=ask(num[i]-1);
        add(num[i],1);
    }
    //现已求出逆序对数量(cnt)，但可以“凑出”交换次数
    if(!(m&1)&&(cnt&1))
        cout<<-1;
    else{
        ll ans=(cnt+m-1)/m;
        ans*=m;//求出最近的m的倍数
        if((ans-cnt)&1)
            ans+=m;//保证奇偶性相同（为偶）
        printf("%lld",ans);
    }
    return 0;
}