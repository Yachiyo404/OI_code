#include<bits/stdc++.h>
#define ll long long
using namespace std;
double a,b,c;
ll signx[10],signy[10],signz[10];
bool flag;
inline bool check(ll l,ll *w){
    ll f=1,sum;
    bool fl=0,book[10]={};
    while(l){
        sum=l%10;
        if(signx[sum]||w[sum]||book[sum]){
            fl=1;
            break;
        }
        book[sum]=1;
        w[sum]=1;
        l/=10;
    }
    if(fl)
        return 0;
    else
        return 1;
}
inline void dfs(ll k,ll x){
    if(k==3){
        memset(signy,0,sizeof(signy));
        memset(signz,0,sizeof(signz));
        ll y=x*(b/a),z=x*(c/a);
        if((x>=100&&x<=999)&&(y>=100&&y<=999)&&(z>=100&&z<=999)&&check(y,signz)&&check(z,signz)){
            bool i=!(signx[0]||signy[0]||signz[0]);
            if(i){
                printf("%lld %lld %lld\n",x,y,z);
                flag=1;
            }
        }
        return;
    }
    x*=10;
    for(ll i=1;i<=9;i++){
        if(!signx[i]){
            signx[i]=1;
            dfs(k+1,x+i);
            signx[i]=0;
        }
    }
}
int main(){
    scanf("%lf%lf%lf",&a,&b,&c);
    dfs(0,0);
    if(!flag)
        printf("No!!!");
}