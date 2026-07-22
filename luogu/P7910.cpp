#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=8e3+10;
ll n,Q;
ll sign[N];
struct node{
    ll data,id;
}num[N];
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
inline bool cmp(node a,node b){
    if(a.data!=b.data)
        return a.data<b.data;
    else
        return a.id<b.id;
}
inline void s(node &a,node &b){
    swap(a.id,b.id);
    swap(a.data,b.data);
}
int main(){
    read(n),read(Q);
    for(ll i=1;i<=n;i++){
        read(num[i].data);
        num[i].id=i;
    }
    stable_sort(num+1,num+n+1,cmp);
    for(ll i=1;i<=n;i++)
        sign[num[i].id]=i;
    while(Q--){
        ll op,x,v;
        read(op);
        if(op==1){
            read(x),read(v);
            num[sign[x]].data=v;
            for(ll j=n;j>=2;j--){
                if(cmp(num[j],num[j-1]))
                    s(num[j],num[j-1]);
            }
            for(ll j=2;j<=n;j++){
                if(cmp(num[j],num[j-1]))
                    s(num[j],num[j-1]);
            }
            for(ll i=1;i<=n;i++)
                sign[num[i].id]=i;
        }
        else{
            read(x);
            printf("%lld\n",sign[x]);
        }
    }
    return 0;
}