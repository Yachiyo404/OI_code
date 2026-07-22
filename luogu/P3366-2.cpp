#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+10;
ll n,m,cnt;
bool sign[N];
struct node{
    ll t,dis;
    bool operator <(const node &a)const{
        return dis>a.dis;
    }
};
vector<node> e[N];
priority_queue<node> q;
ll prim(){
    ll ans=0,cnt=0;
    q.push((node){1,0});
    while(!q.empty()&&cnt<=n){
        node k=q.top();
        q.pop();
        if(sign[k.t])
            continue;
        sign[k.t]=1;
        ans+=k.dis;
        cnt++;
        for(ll i=0;i<e[k.t].size();i++){
            if(!sign[e[k.t][i].t])
                q.push((node){e[k.t][i].t,e[k.t][i].dis});
        }
    }
    if(cnt<n)
        return -1;
    else
        return ans;
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
int main(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        ll x=read(),y=read(),z=read();
        e[x].push_back((node){y,z});
        e[y].push_back((node){x,z});
    }
    ll ans=prim();
    if(ans!=-1)
        printf("%lld",ans);
    else
        printf("orz");
    return 0;
}