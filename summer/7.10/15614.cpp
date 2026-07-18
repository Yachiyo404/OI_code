#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m,r[N];
struct node{int d,s,t;}num[N];
bool check(int mid){
    static ll diff[N];
    for(int i=1;i<=n+1;i++) 
        diff[i]=0;
    for(int i=1;i<=mid;i++){
        diff[num[i].s]+=num[i].d;
        diff[num[i].t+1]-=num[i].d;
    }
    ll cur=0;
    for(int i=1;i<=n;i++){
        cur+=diff[i];
        if(cur>r[i]) 
        return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
        cin>>r[i];
    for(int i=1;i<=m;i++) 
        cin>>num[i].d>>num[i].s>>num[i].t;
    if(check(m)){
        cout<<0<<"\n";
        return 0;
    }
    int L=1,R=m;
    while(L<R){
        int mid=(L+R)>>1;
        if(check(mid)) L=mid+1;
        else R=mid;
    }
    cout<<-1<<"\n"<<L<<"\n";
    return 0;
}