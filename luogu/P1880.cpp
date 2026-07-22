#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll INF=0x7fffffff;
ll n,ans1=INF,ans2;
ll stone[210],sum[210],dp1[210][210],dp2[210][210];
ll dfs1(ll l,ll r){//最小
    if(dp1[l][r])
        return dp1[l][r];
    if(l==r)
        return dp1[l][r]=0;
    ll res=INF;
    for(ll k=l;k<r;k++)
        res=min(res,dfs1(l,k)+dfs1(k+1,r)+stone[r]-stone[l-1]);
    return dp1[l][r]=res;
}
ll dfs2(ll l,ll r){//最大
    if(dp2[l][r])
        return dp2[l][r];
    if(l==r)
        return dp2[l][r]=0;
    ll res=0;
    for(ll k=l;k<r;k++)
        res=max(res,dfs2(l,k)+dfs2(k+1,r)+stone[r]-stone[l-1]);
    return dp2[l][r]=res;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>stone[i];
        stone[i+n]=stone[i];
    }
    for(ll i=1;i<=2*n;i++)
        stone[i]+=stone[i-1];
    dfs1(1,2*n);
    dfs2(1,2*n);
    for(ll i=1;i<=n;i++){
        ans1=min(ans1,dp1[i][i+n-1]);//最小
        ans2=max(ans2,dp2[i][i+n-1]);//最大
    }
    cout<<ans1<<endl<<ans2;
    return 0;
}