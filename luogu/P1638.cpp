#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m,ans,cnt,l=1,r=1,ansl,ansr;
ll pic[N],sign[2005];
inline void add(ll x){
    if(sign[x]==0)
        cnt++;
    sign[x]++;
}
inline void del(ll x){
    if(sign[x]==1)
        cnt--;
    sign[x]--;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&pic[i]);
    ans=n;
    for(;r<=n;r++){
        add(pic[r]);
        while(1){
            del(pic[l]);
            if(cnt==m)
                l++;
            else{
                add(pic[l]);
                break;
            }
        }
        if(cnt==m&&r-l+1<ans){
            ans=r-l+1;
            ansl=l;
            ansr=r;
        }
    }
    if(ansl)
        printf("%lld %lld",ansl,ansr);
    else
        printf("1 %lld",n);    
    return 0;
}