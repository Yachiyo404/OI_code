#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
ll sum[1010][1010];
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
    ll a,b,k,n,m;
    read(a),read(b),read(k),read(n),read(m);
    sum[1][1]=1;
    up(i,1,k+1){
        up(j,1,m+1)
            sum[i][j]=(sum[i-1][j-1]*b+sum[i-1][j]*a)%10007;
    }
    cout<<sum[k+1][m+1];
    return 0;
}