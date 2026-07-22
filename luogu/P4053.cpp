#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1.5e5+10;
ll n,cnt;
struct node{
    ll t,bro;
}build[N];
inline bool cmp(node a,node b){
    return a.bro<b.bro;
}
priority_queue<ll> q;
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
    n=read();
    for(ll i=1;i<=n;i++){
        build[i].t=read();
        build[i].bro=read();
    }
    stable_sort(build+1,build+n+1,cmp);
    ll sum=0;
    for(ll i=1;i<=n;i++){
        sum+=build[i].t;
        q.push(build[i].t);
        if(sum<=build[i].bro)
            cnt++;
        else{
            sum-=q.top();
            q.pop();
        }
    }
    cout<<cnt;
    return 0;
}