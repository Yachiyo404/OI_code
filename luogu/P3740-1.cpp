#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+10;
ll n,m,j=1,mr;
ll wall[N],sign[1005];
inline ll read(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main(){
    n=read();m=read();
    while(m--){
        ll l,r;
        l=read();r=read();
        for(ll i=l;i<=r;i++)
            wall[i]=j;
        j++;
        mr=max(r,mr);
    }
    sign[0]=1;
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        if(!sign[wall[i]]){
            cnt++;
            sign[wall[i]]=1;
        }
    }
    cout<<cnt;
    return 0;
}