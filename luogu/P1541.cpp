#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,c1,c2,c3,c4;
ll num[400],dp[50][50][50][50];
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
    for(ll i=1;i<=n;i++)
        read(num[i]);
    for(ll i=1;i<=m;i++){
        ll a;
        read(a);
        switch(a){
            case 1:
                c1++;
                break;
            case 2:
                c2++;
                break;
            case 3:
                c3++;
                break;
            case 4:
                c4++;
        }
    }
    dp[0][0][0][0]=num[1];
    for(ll i=0;i<=c1;i++){
        for(ll j=0;j<=c2;j++){
            for(ll k=0;k<=c3;k++){
                for(ll l=0;l<=c4;l++){
                    if(i!=0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+num[1+i+j*2+k*3+l*4]);
                    if(j!=0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+num[1+i+j*2+k*3+l*4]);
                    if(k!=0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+num[1+i+j*2+k*3+l*4]);
                    if(l!=0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+num[1+i+j*2+k*3+l*4]);
                }
            }
        }    
    }
    printf("%lld",dp[c1][c2][c3][c4]);
    return 0;
}