#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=210;
ll n,na,nb,cnta,cntb;
ll a[N],b[N];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
int main(){
    read(n),read(na),read(nb);
    for(ll i=1;i<=na;i++)
        read(a[i]);
    for(ll i=1;i<=nb;i++)
        read(b[i]);
    for(ll i=1;i<=n;i++){
        ll nowa=i%na,nowb=i%nb;
        if(!nowa)
            nowa=na;
        if(!nowb)
            nowb=nb;
        if(a[nowa]==0&&b[nowb]==1)
            cntb++;
        if(a[nowa]==0&&b[nowb]==2)
            cnta++;
        if(a[nowa]==0&&b[nowb]==3)
            cnta++;
        if(a[nowa]==0&&b[nowb]==4)
            cntb++;
        if(a[nowa]==1&&b[nowb]==2)
            cntb++;
        if(a[nowa]==1&&b[nowb]==3)
            cnta++;
        if(a[nowa]==1&&b[nowb]==4)
            cntb++;
        if(a[nowa]==2&&b[nowb]==3)
            cntb++;
        if(a[nowa]==2&&b[nowb]==4)
            cnta++;
        if(a[nowa]==3&&b[nowb]==4)
            cnta++;
        if(b[nowb]==0&&a[nowa]==1)
            cnta++;
        if(b[nowb]==0&&a[nowa]==2)
            cntb++;
        if(b[nowb]==0&&a[nowa]==3)
            cntb++;
        if(b[nowb]==0&&a[nowa]==4)
            cnta++;
        if(b[nowb]==1&&a[nowa]==2)
            cnta++;
        if(b[nowb]==1&&a[nowa]==3)
            cntb++;
        if(b[nowb]==1&&a[nowa]==4)
            cnta++;
        if(b[nowb]==2&&a[nowa]==3)
            cnta++;
        if(b[nowb]==2&&a[nowa]==4)
            cntb++;
        if(b[nowb]==3&&a[nowa]==4)
            cntb++;
    }
    printf("%lld %lld",cnta,cntb);
    return 0;
}