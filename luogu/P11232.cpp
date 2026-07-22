#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll T,n,m,L,V;
ll road[N],ce[N];
struct c{
    ll sp,a,pos;
    bool sign;
}car[N];
inline ll read(){
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
    return x*f;
}
int main(){
    T=read();
    while(T--){
        ll ans1=0,ans2=0;
        //memset(car,0,sizeof(car));
        //memset(road,0,sizeof(road));
        n=read(),m=read(),L=read(),V=read();
        for(ll i=1;i<=n;i++){
            car[i].pos=read();
            car[i].sp=read();
            car[i].a=read();
            if(car[i].sp<=V&&car[i].a<=0)
                car[i].sign=1;
        }
        for(ll i=1;i<=m;i++)
            road[i]=read();
        stable_sort(road+1,road+1+m);
        for(ll i=1;i<=n;i++){
            if(!car[i].sign){
                if(car[i].a>0){
                    if(car[i].sp>=V){
                        
                    }
                    else{

                    }
                }
                else{
                    if(car[i].sp>=V){
                        
                    }
                }
            }
        }
    }
    return 0;
}