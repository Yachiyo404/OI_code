#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e3+10;
int t,n,cnt;
int fa[N],siz[N];
struct edge{
    int u,v,w;
};
void init(){
    cnt=0;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        siz[i]=1;
    }
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
    siz[y]+=siz[x];
}
int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        vector<edge> e;
        ll ans=0;
        cin>>n;
        init();
        for(int i=1;i<=n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            e.push_back({u,v,w});
            e.push_back({v,u,w});
        }
        sort(e.begin(),e.end(),[](edge a,edge b){return a.w<b.w;});
        for(auto i:e){
            int u=find(i.u),v=find(i.v),w=i.w;
            if(u==v)
                continue;
            ans+=(siz[u]*siz[v]-1)*(w+1);
            merge(u,v);
            cnt++;
            if(cnt==n-1)
                break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}