#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
using namespace std;
typedef long long ll;
ll x_0,y_0,m,n;
ll dp[25][25];
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
    read(n),read(m),read(x_0),read(y_0);
    n++,m++;
    x_0++,y_0++;
    swap(x_0,y_0);
    dp[1][1]=1;
    dp[y_0][x_0]=-1;
    if(x_0+2<=n&&y_0+1<=m)
        dp[y_0+1][x_0+2]=-1;
    if(x_0+1<=n&&y_0+2<=m)
        dp[y_0+2][x_0+1]=-1;
    if(x_0-1>=1&&y_0+2<=m)
        dp[y_0+2][x_0-1]=-1;
    if(x_0-2>=1&&y_0+1<=m)
        dp[y_0+1][x_0-2]=-1;
    if(x_0-2>=1&&y_0-1>=1)
        dp[y_0-1][x_0-2]=-1;
    if(x_0-1>=1&&y_0-2>=1)
        dp[y_0-2][x_0-1]=-1;
    if(x_0+1<=n&&y_0-2>=1)
        dp[y_0-2][x_0+1]=-1;
    if(x_0+2<=n&&y_0-1>=1)
        dp[y_0-1][x_0+2]=-1;
    up(i,1,n){
        up(j,1,m){
            if(i==1&&j==1)
                continue;
            if(dp[i][j]!=-1)
                dp[i][j]=max(0ll,dp[i-1][j])+max(0ll,dp[i][j-1]);
        }
    }
    // up(i,1,n){
    //     up(j,1,m)
    //         printf("%lld ",dp[i][j]);
    //     printf("\n");
    // }
    cout<<dp[n][m];
    return 0;
}