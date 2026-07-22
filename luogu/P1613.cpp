#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll dis[60][60]={};
bool g[60][60][65]={};
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
    memset(dis,10,sizeof(dis));
    memset(g,0,sizeof(g));
    for(ll i=1;i<=m;i++){
        ll a,b;
        read(a),read(b);
        dis[a][b]=1;
        g[a][b][0]=1;
    }
    for(ll k=1;k<=64;k++){
        for(ll i=1;i<=n;i++){
            for(ll t=1;t<=n;t++){
                for(ll j=1;j<=n;j++){
                    if(g[i][t][k-1]&&g[t][j][k-1]){
                        g[i][j][k]=1;
                        dis[i][j]=1;
                    }
                }
            }
        }
    }
    for(ll s=1;s<=n;s++){//中间点循环一定在最外面
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][s]+dis[s][j]);
        }
    }
    cout<<dis[1][n];
    return 0;
}