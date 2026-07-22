#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
vector<ll> ans;
inline void read(ll &a){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x;
}
int main(){
    read(n),read(k);
    ans.push_back(2);
    for(ll i=3;i<=n+10;i+=2){
        ll b=3,m=ceil(sqrt(i));
        bool flag=0;
        while(b<=m){
            if(i%b==0){
                flag=1;
                break;
            }
            b+=2;
        }
        if(!flag)
            ans.push_back(i);
    }
    for(ll i=1;i<=k;i++){
        ll a;
        read(a);
        printf("%lld\n",ans[a-1]);
    }
    int a='m';
    return 0;
}
