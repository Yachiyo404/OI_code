#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll dp[10][90][600],cnt[600];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(ll s=0;s<=(1<<n)-1;s++)
        cnt[s]=__builtin_popcount(s);
    dp[0][0][0]=1;
    for(ll i=1;i<=n;i++){
        for(ll s=0;s<=(1<<n)-1;s++){
            for(ll t=0;t<=(1<<n)-1;t++){
                bool flag1=(s&t)==0&&((s<<1)&t)==0&&((s>>1)&t)==0;
                bool flag2=((s>>1)&s)==0&&((s<<1)&s)==0&&((t>>1)&t)==0&&((t<<1)&t)==0;
                if(flag1&&flag2){
                    for(ll j=k;j>=0;j--){
                        if(j-cnt[s]>=0)
                            dp[i][j][s]+=dp[i-1][j-cnt[s]][t];
                    }
                }
            }
        }
    }
    ll ans=0;
    for(ll s=0;s<=(1<<n)-1;s++){
        if(((s>>1)&s)==0&&((s<<1)&s)==0)
            ans+=dp[n][k][s];
    }
    cout<<ans;
    return 0;
}