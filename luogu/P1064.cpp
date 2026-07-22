#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll v[65][3],p[65][3],f[(int)3.2e4+10];
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
inline ll cost1(ll x,ll y,ll id){
    return v[id][x]+v[id][y];
}
inline ll cost2(ll x,ll y,ll z,ll id){
    return v[id][x]+v[id][y]+v[id][z];
};
inline ll rpp(ll x,ll id){
    return v[id][x]*p[id][x];
};
int main(){
    read(n),read(m);
    for(ll i=1;i<=m;i++){
        ll a,b,c;
        read(a),read(b),read(c);
        if(c==0){
            v[i][0]=a;
            p[i][0]=b;
        }
        else{
            if(v[c][1]==0){
                v[c][1]=a;
                p[c][1]=b;
            }
            else{
                v[c][2]=a;
                p[c][2]=b;
            }
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=n;j>=0;j--){
            if(j>=v[i][0])
                f[j]=max(f[j],f[j-v[i][0]]+rpp(0,i));
            if(j>=cost1(0,1,i))
                f[j]=max(f[j],f[j-cost1(0,1,i)]+rpp(0,i)+rpp(1,i));
            if(j>=cost1(0,2,i))
                f[j]=max(f[j],f[j-cost1(0,2,i)]+rpp(0,i)+rpp(2,i));
            if(j>=cost2(0,1,2,i))
                f[j]=max(f[j],f[j-cost2(0,1,2,i)]+rpp(0,i)+rpp(1,i)+rpp(2,i));
        }
    }
    printf("%lld",f[n]);
    return 0;
}