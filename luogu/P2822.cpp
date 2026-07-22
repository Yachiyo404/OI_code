#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
ll T,k;
ll c[2010][2010],a[2010][2010];
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
    read(T),read(k);
    up(i,0,2000){
        up(j,0,i){
            if(j==0||j==i)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
        }
    }
    up(i,1,2000){
        up(j,1,2000){
            if(j<=i)
                a[i][j]=a[i-1][j]-a[i-1][j-1]+a[i][j-1]+(c[i][j]%k==0);
            else
                a[i][j]=a[i][i];
        }
    }
    while(T--){
        ll n,m;
        read(n),read(m);
        cout<<a[n][min(n,m)]<<endl;
    }
    return 0;
}