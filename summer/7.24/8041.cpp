#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
ll n,p,cnt,ans;
ll p_w[N],fa[N];
struct edge{
    ll u,v,w;
};
void init(){
    for(ll i=1;i<=n;i++)
        fa[i]=i;
}
ll find(ll x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
    x=find(x),y=find(y);
    fa[x]=y;
}
vector<edge> e;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>p;
    init();
    for(ll i=1;i<=n;i++)
        cin>>p_w[i];
    for(ll i=1;i<=p;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,2*w+p_w[u]+p_w[v]});
        e.push_back({v,u,2*w+p_w[u]+p_w[v]});
    }
    sort(e.begin(),e.end(),[](edge a,edge b){return a.w<b.w;});
    for(auto i:e){
        ll u=find(i.u),v=find(i.v),w=i.w;
        if(u==v)
            continue;
        ans+=w;
        merge(u,v);
        cnt++;
        if(cnt==n-1)
            break;
    }
    sort(p_w+1,p_w+n+1);
    ans+=p_w[1];
    cout<<ans;
    return 0;
}