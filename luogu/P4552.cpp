#include<bits/stdc++.h>
#define ll long long
#define mem(a,m) memset(a,m,sizeof(a))
using namespace std;
const ll MAXN=100005;
ll n,num[MAXN],difference[MAXN],positive,negative,j=1;
inline ll read(){
        ll x=0,f=1;
        char ch=getchar();
        while(ch<'0'||ch>'9'){
            if(ch=='-')
                f=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=x*10+(ch-'0');
            ch=getchar();
        }
        return x*f;
}
int main(){
    n=read();
    for(ll i=1;i<=n;i++){
        num[i]=read();
        difference[i]=num[i]-num[i-1];
    }
    while(j<=n-1){
        j++;
        if(difference[j]>0)
            positive+=difference[j];
        else if(difference[j]<0)
            negative+=llabs(difference[j]);
    }
    printf("%lld\n%lld",max(positive,negative),llabs(positive-negative)+1);
    return 0;
}