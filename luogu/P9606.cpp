#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
const int N=8e5+10;
ll n;
ll nex[N];
char str[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>str+n+2;
    str[n+1]='&';
    for(ll i=1,j=2*n+1;i<=n;i++,j--)
        str[i]=str[j];
    ll pos=0;
    up(i,2,2*n+1){
        while(pos&&str[pos+1]!=str[i])
            pos=nex[pos];
        if(str[pos+1]==str[i])
            pos++;
        nex[i]=pos;
    }
    printf("%lld",n-nex[2*n+1]);
    return 0;
}