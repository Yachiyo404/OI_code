#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
ll n,m;
ll num[N],bit[N],ans[N];
struct node{
    ll high,pos;
}hair[N];
inline bool cmp(node a,node b){
    return a.high<b.high;
}
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
inline ll lowbit(ll x){
    return x&-x;
}
inline ll ask(ll x){
    ll sum=0;
    while(x){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
inline void add(ll x,ll y){
    while(x<=n){
        bit[x]+=y;
        x+=lowbit(x);
    }
}
int main(){
    n=read();
    for(ll i=1;i<=n;i++){
        hair[i].high=read();
        hair[i].pos=i;
    }
    stable_sort(hair+1,hair+n+1,cmp);
    for(ll i=n;i>=1;i--){
        if(hair[i].high==hair[i-1].high)
            hair[i].high=-1;
    }
    for(ll i=1;i<=n;i++){
        if(hair[i].high==-1&&i>1)
            num[hair[i].pos]=num[hair[i-1].pos];
        else
            num[hair[i].pos]=i;
    }
    /*for(ll i=1;i<=n;i++)
        cout<<num[i]<<" ";*/
    for(ll i=n;i>=1;i--){
        
    }
    return 0;
}