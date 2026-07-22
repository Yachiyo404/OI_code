#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;x++)
#define down(x,a,b) for(ll x=a;x>=b;x--)
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m;
ll p[N],q[N],k[N];
bool flag[N];
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
    read(n),read(m);
    ll t=0;
    up(i,2,n){
        if(!flag[i]){
            p[++t]=i;
            q[i]=t;
        }
        for(ll j=1;j<=t&&p[j]*i<=n;++j){
            ll a=p[j]*i;
            flag[a]=1;
            q[a]=j;
            if(i%p[j]==0)
                break;
        }
    }
    memset(flag,0,sizeof(flag));
    while(m--){
        char ch;
        ll x,a;
        cin>>ch;
        read(x);
        a=x;
        if(ch=='+'){
            if(flag[x]){
                puts("Already on");
                continue;
            }
            while(x>1){
                if(k[q[x]])
                    break;
                x/=p[q[x]];
            }
            if(x!=1){
                printf("Conflict with %lld\n",k[q[x]]);
                continue;
            }
            x=a;
            flag[a]=1;
            puts("Success");
            while(x>1){
                k[q[x]]=a;
                x/=p[q[x]];
            }
        }
        else{
            if(!flag[a]){
                puts("Already off");
                continue;
            }
            flag[a]=0;
            puts("Success");
            while(x>1){
                k[q[x]]=0;
                x/=p[q[x]];
            }
        }
    }
    return 0;
}