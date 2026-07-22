#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,k,l,d;
struct node{
    ll x,n;
}x[1010],y[1010];
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
inline bool cmp1(node a,node b){
    return a.n>b.n;
}
inline bool cmp2(node a,node b){
    return a.x<b.x;
}
int main(){
    read(m),read(n),read(k),read(l),read(d);
    for(ll i=1;i<=d;i++){
        ll x1,y1,p1,q1;
        read(x1),read(y1),read(p1),read(q1);
        if(x1==p1){
            y[min(y1,q1)].x=min(y1,q1);
            y[min(y1,q1)].n++;
        }
        if(y1==q1){
            x[min(x1,p1)].x=min(x1,p1);
            x[min(x1,p1)].n++;
        }
    }
    sort(x+1,x+1000+1,cmp1);
    sort(y+1,y+1000+1,cmp1);
    sort(x+1,x+k+1,cmp2);
    sort(y+1,y+l+1,cmp2);
    for(ll i=1;i<=k;i++)
        printf("%lld ",x[i].x);
    putchar('\n');
    for(ll i=1;i<=l;i++)
        printf("%lld ",y[i].x);
    return 0;
}