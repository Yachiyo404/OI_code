#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,cnt;
ll sign[20][20];
inline void dfs(ll x,ll y){
    ll nx=x,ny=y;
    if(x==m&&y==n){
        cnt++;
        return;
    }
    for(ll i=1;i<=4;i++){
        switch(i){
            case 1:
                nx=x+2;
                ny=y+1;
                break;
            case 2:
                nx=x+1;
                ny=y+2;
                break;
            case 3:
                nx=x+2;
                ny=y-1;
                break;
            case 4:
                nx=x+1;
                ny=y-2;
        }
        if(!sign[ny][nx]&&(0<=nx&&nx<=m)&&(0<=ny&&ny<=n)){
            sign[ny][nx]=1;
            dfs(nx,ny);
            sign[ny][nx]=0;
        }
    }
}
int main(){
    scanf("%lld%lld",&n,&m);
    dfs(0,0);
    printf("%lld",cnt);
    return 0;
}