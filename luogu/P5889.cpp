#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
typedef long long ll;
using namespace std;
const int N=5e5+10;
ll op[N];
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
inline void write(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) 
        write(x/10);
    putchar(x%10+'0');
}
inline void change(ll n){
    up(i,1,n){

    }
}
int main(){
    ll n=read(),m=read(),q=read();
    up(i,1,m)
        op[i]=read();
    change(n);
    while(q--){
        ll type=read();
        if(type==1){
            ll s=read(),l=read(),r=read(),pos=s;
            up(i,l,r){
                if(op[i]==1)
                    pos=2*pos;
                else if(op[i]==2)
                    pos=2*pos+1;
                else{
                    if(pos!=1){
                        if(pos%2)
                            pos--;
                        pos/=2;
                    }   
                }
            }
            write(pos);
            putchar('\n');
        }
        else{
            ll x=read(),y=read();
            op[x]=y;
            change(n);
        }
    }
    return 0;
}