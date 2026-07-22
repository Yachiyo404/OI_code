#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+10;
ll n,ans;
struct obj{
    ll v,x;
}cow[N];
int main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld",&cow[i].v,&cow[i].x);
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++)
            ans+=max(cow[i].v,cow[j].v)*llabs(cow[i].x-cow[j].x);
    }
    printf("%lld",ans);
    return 0;
}