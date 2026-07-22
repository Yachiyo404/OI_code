#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
ll m;
ll fbn[70]={0,1,1,2},a[70],b[70];
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
    for(ll i=4;i<=60;i++)
        fbn[i]=fbn[i-1]+fbn[i-2];
    read(m);
    while(m--){
        ll x,y,ans=1;
        read(x),read(y);
        x--;
        y--;
        for(ll i=59;i>=1;i--){
            a[i]=x/fbn[i];
            x%=fbn[i];
        }
        for(ll i=59;i>=1;i--){
            b[i]=y/fbn[i];
            y%=fbn[i];
        }
        for(ll i=0;i<=59;i++,ans+=fbn[i]*a[i]){
            if(a[i+1]!=b[i+1])
                break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}