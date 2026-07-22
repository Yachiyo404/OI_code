#include<bits/stdc++.h>
#define ll long long
#define mem(a,m) memset(a,m,sizeof(a))
using namespace std;
const ll N=2e6+1;
ll n,m,lt,rt,ans;
ll Max_num[N][30],Min_num[N][30];
ll findmax(ll l,ll r){
    ll lg=log2(r-l+1);
    return max(Max_num[l][lg],Max_num[r-(1<<lg)+1][lg]);
}
ll findmin(ll l,ll r){
    ll lg=log2(r-l+1);
    return min(Min_num[l][lg],Min_num[r-(1<<lg)+1][lg]);
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&Max_num[i][0]);
        Min_num[i][0]=Max_num[i][0];
    }
    for(ll j=1;j<=25;j++){
        for(ll i=1;i+(1<<j)-1<=n;i++)
            Max_num[i][j]=max(Max_num[i][j-1],Max_num[i+(1<<(j-1))][j-1]);
    }
    for(ll j=1;j<=25;j++){
        for(ll i=1;i+(1<<j)-1<=n;i++)
            Min_num[i][j]=min(Min_num[i][j-1],Min_num[i+(1<<(j-1))][j-1]);
    }
    for(ll i=1;i<=m;i++){
        scanf("%lld%lld",&lt,&rt);
        ans=findmax(lt,rt)-findmin(lt,rt);
        printf("%lld\n",ans);
    }
    return 0;
}