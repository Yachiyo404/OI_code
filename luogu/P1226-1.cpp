#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll fast(ll a,ll b,ll p){
    if(b==0)
        return 1;
    if(b==1)
        return a%p;
    ll ans=fast(a,b/2,p);
    if(b%2==1)
        return (ans%p*ans%p)*a%p;
    else
        return ans%p*ans%p;
}
int main(){
    ll a,b,p;
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,fast(a,b,p));
    return 0;
}
//快速幂分治写法