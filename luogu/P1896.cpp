#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int n,k,num;
ll cnt[2000],ok[2000],dp[10][100][2000];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    up(s,0,(1<<n)-1){
        int tot=0,s1=s;
        while(s1){
            if(s1&1)
                tot++;
            s1>>=1;
        }
        cnt[s]=tot;
        if((((s<<1)|(s>>1))&s)==0)
            ok[++num]=s;
    }
    dp[0][0][0]=1;
    up(i,1,n){
        up(l,1,num){
            int s1=ok[l];
            up(r,1,num){
                int s2=ok[r];
                if(((s2|(s2<<1)|(s2>>1))&s1)==0){
                    up(j,0,k){
                        if(j-cnt[s1]>=0)
                            dp[i][j][s1]+=dp[i-1][j-cnt[s1]][s2];
                    }
                }
            }
        }
    }
    ll ans=0;
    up(i,1,num)
        ans+=dp[n][k][ok[i]];
    cout<<ans;
    return 0;
}