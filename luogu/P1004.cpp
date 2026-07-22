#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll map_xy[15][15],dp[15][15][15][15];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    while(1){
        ll x,y,num;
        cin>>y>>x>>num;
        if(x!=0&&y!=0)
            map_xy[y][x]=num;
        else
            break;
    }
    /*for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)
            cout<<map_xy[i][j]<<" ";
        cout<<endl;
    }*/
    dp[1][1][1][1]=map_xy[1][1];
    for(ll i1=1;i1<=n;i1++){
        for(ll j1=1;j1<=n;j1++){
            for(ll i2=1;i2<=n;i2++){
                for(ll j2=1;j2<=n;j2++){
                    ll max_pre=max({dp[i1-1][j1][i2-1][j2],dp[i1-1][j1][i2][j2-1],dp[i1][j1-1][i2][j2-1],dp[i1][j1-1][i2-1][j2]});
                    //cout<<max_pre<<endl;
                    dp[i1][j1][i2][j2]=max_pre+map_xy[i1][j1]+map_xy[i2][j2];
                    if(i1==i2&&j1==j2)
                        dp[i1][j1][i2][j2]-=map_xy[i1][j1];
                }
            }
        }
    }
    cout<<dp[n][n][n][n];
    return 0;
}