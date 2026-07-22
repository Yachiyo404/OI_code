#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll fast(ll a,ll b,ll p){
    ll sum=1;
    a%=p;
    while(b>0){
        if(b&1)
            sum=(sum*a)%p;
        b=b>>1;
        a=(a*a)%p;
    }
    return sum;
}
int main(){
    ll a,b,p;
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,fast(a,b,p));
    return 0;
}
//快速幂正解