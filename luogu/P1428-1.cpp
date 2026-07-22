#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt;
ll cute[105];
int main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&cute[i]);
    for(ll i=1;i<=n;i++){
        cnt=0;
        for(ll j=i-1;j>=1;j--){
            if(cute[j]<cute[i])
                cnt++;
        }
        printf("%lld ",cnt);
    }
    return 0;
}